

#ifndef UNTITLED_QUATERNION_H
#define UNTITLED_QUATERNION_H

#include <iostream>
#include <vector>
#include "Vector.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI

using namespace std;

class Quaternion {
private:
    //double w, x, y, z;

public:
    double w, x, y, z;
    Quaternion();
    Quaternion(double _w, double _x, double _y, double _z);

    static Quaternion RotatePoint(std::vector<float> point, float angle, std::vector<float> axis);
    

    Quaternion operator+(const Quaternion& value);
    Quaternion operator-(const Quaternion& value);

    Quaternion operator+(const int value);
    Quaternion operator-(const int value);

    Quaternion operator+(const float value);
    Quaternion operator-(const float value);

    Quaternion operator*(const Quaternion& value);
    Quaternion operator*(int value);
    Quaternion operator*(float value);

    std::string toString();
};

#endif //UNTITLED_QUATERNION_H
