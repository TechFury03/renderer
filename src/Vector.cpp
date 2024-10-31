#include "../include/Vector.h"

/* Vector */

void 
Vector::setX(float x){
  this->x = x;
}

void 
Vector::setY(float y){
  this->y = y;
}

float 
Vector::getX() const{
  return this->x;
}

float 
Vector::getY() const{
  return this->y;
}

/* Vector2D::Constructors/Destructors */

Vector2D::Vector2D(){
  this->x = 0.0;
  this->y = 0.0;
}

Vector2D::Vector2D(float x){
  this->x = x;
  this->y = 0.0;
}

Vector2D::Vector2D(float x, float y){
  this->x = x;
  this->y = y;
}

Vector2D::~Vector2D(){}

/* Vector2D::Operators */

std::ostream&
operator<<(std::ostream &os, const Vector2D &v){
  return os << "[" << std::to_string(v.x) << ", " << std::to_string(v.y) << "]";
}

Vector2D
operator*(Scalar s, const Vector2D &v){
  return Vector2D(v.x*s, v.y*s);
}

Vector2D
operator*(const Vector2D &v, Scalar s){
  return Vector2D(v.x*s, v.y*s);
}

Vector2D 
operator+(const Vector2D &v1, const Vector2D &v2){
  return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

Vector2D 
operator-(const Vector2D &v1, const Vector2D &v2){
  return Vector2D(v1.x - v2.x, v1.y - v2.y);
}

Scalar 
operator*(const Vector2D &v1, const Vector2D &v2){
  return v1.x*v2.x + v1.y*v2.y;
}

/* Vector2D::Member functions*/

std::string
Vector2D::toString() const {
  return "[" + std::to_string(x) + ", " + std::to_string(y) + "]"; 
}

/* Vector3D */
