#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include<cmath>
#include<string>
#include <sstream>

class Vector
{
private:
    

public:
    float x;
    float y;
    float z;
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

    static void RotateX(Vector& v, float angle)
    {
        v.y = v.y * cosf(3.1415f * angle / 180) - v.z * sinf(3.1415f * angle / 180);
        v.z = v.y * sinf(3.1415f * angle / 180) + v.z * cosf(3.1415f * angle / 180);
    }

    static void RotateY(Vector& v, float angle)
    {
        v.x = v.x * cosf(3.1415f * angle / 180) + v.z * sinf(3.1415f * angle / 180);
        v.z = -1.0f * v.x * sinf(3.1415f * angle / 180) + v.z * cosf(3.1415f * angle / 180);
    }

    static void RotateZ(Vector& v, float angle)
    {
        v.x = v.x * cosf(3.1415f * angle / 180) - v.y * sinf(3.1415f * angle / 180);
        v.y = v.x * sinf(3.1415f * angle / 180) + v.y * cosf(3.1415f * angle / 180);
    }

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
