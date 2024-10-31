#ifndef VECTOR_H
#define VECTOR_H

#include "string"
#include <iostream>

using Scalar = float;

class Vector {
  public:

    void setX(float x);
    void setY(float y);

    float getX() const;
    float getY() const;

    virtual std::string toString() const = 0;

  protected:
    float x, y;
};

class Vector2D : public Vector {
  public:
    /* Constructors/Destructors*/
    Vector2D();
    Vector2D(float x);
    Vector2D(float x, float y);
    ~Vector2D();

    /* Operators */
    friend std::ostream& operator<<(std::ostream &os, const Vector2D &v);

    friend Vector2D operator*(Scalar s, const Vector2D &v);
    friend Vector2D operator*(const Vector2D &v, Scalar s);

    friend Vector2D operator+(const Vector2D &v1, const Vector2D &v2);
    friend Vector2D operator-(const Vector2D &v1, const Vector2D &v2);

    friend Scalar operator*(const Vector2D &v1, const Vector2D &v2);

    /* Member functions */
    std::string toString() const override;

    /*
      TODO:
        plot
    */

};

class Vector3D : Vector {
  public:
    Vector3D();
    ~Vector3D();

    void setZ(float z);

    float getZ() const;

  private:
    float z;
};

#endif // VECTOR_H