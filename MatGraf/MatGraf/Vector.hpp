#ifndef VECTOR_HPP
#define VECTOR_HPP

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <iostream>
#include<cmath>

class Vector
{
private:
    float x;
    float y;
    float z;

public:
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


    static float dot(const Vector& w, const Vector& v);

    static float angle(const Vector& from, const Vector& to);

    static Vector cross(const Vector& w, const Vector& v);

    static float distance(const Vector& w, const Vector& v);

    static void noramlizeThis(Vector& w);

    static Vector scale(const Vector& w, const Vector& v);

    Vector operator+(const float& a);
    Vector operator-(const float& a);
    Vector operator*(const float& a);
    Vector operator/(const float& a);

    Vector operator+(const Vector& a);
    Vector operator-(const Vector& a);
    Vector operator*(const Vector& a);
    Vector operator/(const Vector& a);
};

#endif // !VECTOR_HPP
