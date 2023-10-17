#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include<cmath>
#include<string>
#include <sstream>

class Vector
{
private:
    float x;
    float y;
    float z;

public:

    // Public methods
    Vector();

    Vector(const float& new_x, const float& new_y, const float& new_z);

    float getMagnitude() const;

    float inverseSqrtMagnitude() const;

    void normalize();

    float getX() const;

    float getY() const;

    float getZ() const;

    void setX(const float& value);

    void setY(const float& value);

    void setZ(const float& value);

    void set(const float& new_x, const float& new_y, const float& new_z);

    void zero();

    std::string toString() const;


    // Static methods
    static float dot(const Vector& w, const Vector& v);

    static float angle(const Vector& from, const Vector& to);

    static Vector cross(const Vector& w, const Vector& v);

    static float distance(const Vector& w, const Vector& v);

    static void noramlizeThis(Vector& w);

    Vector lerp(Vector& w, Vector& v, const float& t);

    void zeroThis(Vector& w);

    // Operators
    Vector operator+(const int& a);
    Vector operator-(const int& a);
    Vector operator*(const int& a);
    Vector operator/(const int& a);

    Vector operator+(const float& a);
    Vector operator-(const float& a);
    Vector operator*(const float& a);
    Vector operator/(const float& a);

    Vector operator+(const Vector& a);
    Vector operator-(const Vector& a);
    Vector operator*(const Vector& a);
    Vector operator/(const Vector& a);
    float operator^(const Vector& a);
};

#endif // !VECTOR_HPP
