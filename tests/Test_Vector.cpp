#define BOOST_TEST_MODULE Test_Vector

#include <boost/test/included/unit_test.hpp>
#include "Vector.h"
#include <iostream>

BOOST_AUTO_TEST_CASE(VectorOperands)
{
    /* Create vectors to test */
    Vector2D v1 = Vector2D(1.0, 1.0);
    Vector2D v2 = Vector2D(2.0, 2.0);

    /* Test addition */
    Vector2D v3 = v1+v2;
    BOOST_CHECK(v3.getX() == v1.getX() + v2.getX());
    BOOST_CHECK(v3.getY() == v1.getY() + v2.getY());

    /* Test subtraction */
    v3 = v1-v2;
    BOOST_CHECK(v3.getX() == v1.getX() - v2.getX());
    BOOST_CHECK(v3.getY() == v1.getY() - v2.getY());

    /* Test scalar multiplication, both ways */
    Scalar s = 3.0f;
    v3 = v1*s;
    BOOST_CHECK(v3.getX() == v1.getX() * s);
    BOOST_CHECK(v3.getY() == v1.getY() * s);

    v3 = s*v1;
    BOOST_CHECK(v3.getX() == (Scalar) (v1.getX() * s));
    BOOST_CHECK(v3.getY() == (Scalar) (v1.getY() * s));

    /* Test vector multiplication */
    s = v1*v2;
    BOOST_CHECK(s == v1.getX() * v2.getX() + v1.getY() * v2.getY());
}