#directories
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests

#files 
HEADER = $(sort $(shell find $(INC_DIR) -maxdepth 1 -name '*.h'))
SOURCES = $(sort $(shell find $(SRC_DIR) -maxdepth 1 -name '*.cpp'))
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)

#test files
TEST_SOURCES = $(sort $(shell find $(TEST_DIR) -maxdepth 1 -name '*.cpp'))
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.cpp=$(TEST_DIR)/%.o)

#name for the program to compile
TARGET = main
TEST_TARGET = test_Vector

#compiler
CXX = g++

#compile flags
CFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -ggdb3 -I$(INC_DIR)

#boost lib
BOOST_LIBS = -lboost_unit_test_framework

.PHONY: all clean debug release

#build types
release: CFLAGS += -O3 -DNDEBUG
release: all
debug: CFLAGS += -O0 -DDEBUG -ggdb3
debug: all

#default build
all: $(TARGET)

#compile .cpp files to .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

#linking target
$(TARGET): $(OBJECTS) main.cpp
	$(CXX) $(CFLAGS) $(OBJECTS) main.cpp -o $(TARGET)

#test target
test: all $(TEST_TARGET)
	./$(TEST_TARGET)

#compile test .cpp files to .o files
$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

#linking test target
$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(CFLAGS) $(TEST_OBJECTS) $(OBJECTS) -o $(TEST_TARGET) $(BOOST_LIBS)

#clean up build files
clean:
	rm -f $(SRC_DIR)/*.o $(TEST_DIR)/*.o $(TARGET)
