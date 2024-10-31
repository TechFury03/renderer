#include "../include/Vector.h"
#include <iostream>

int main(int argc, char* argv[]){
    Vector2D v1 = Vector2D(1.5, 4.5);
    Vector2D v2 = Vector2D(2.0);

    std::cout << "v1: " << v1.toString() << std::endl;
    std::cout << "v2: " << v2.toString() << std::endl;

    Vector2D v3 = v1 + v2;

    std::cout << "v3: " << v3.toString() << std::endl;

    std::cout <<v3 <<std::endl;
    return 0;
}