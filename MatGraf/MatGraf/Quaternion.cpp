#include "Quaternion.h"
#include <string>
#include <sstream>

Quaternion::Quaternion() : w(0.0), x(0.0), y(0.0), z(0.0) {}

Quaternion::Quaternion(double _w, double _x, double _y, double _z) : w(_w), x(_x), y(_y), z(_z) {}

Quaternion Quaternion::RotatePoint(std::vector<float> point, float angle, std::vector<float> axis)
{
    Quaternion p = Quaternion(0.0f, point[0], point[1], point[2]);

    float sine = sinf((M_PI * angle / 180) / 2);
    float cosine = cosf((M_PI * angle / 180) / 2);

    Quaternion q = Quaternion(cosine, sine * axis[0], sine * axis[1], sine * axis[2]);
    Quaternion q_con = Quaternion(q.w, -q.x, -q.y, -q.z);

    return (q * p) * q_con;
}

Quaternion Quaternion::operator+(const Quaternion& value) {
    return Quaternion(w + value.w, x + value.x, y + value.y, z + value.z);
}

Quaternion Quaternion::operator-(const Quaternion& value){
    return Quaternion(w - value.w, x - value.x, y - value.y, z - value.z);
}

Quaternion Quaternion:: operator+(int value) {
    return Quaternion(w + value, x + value, y + value, z + value);
}


Quaternion Quaternion:: operator+(float value) {
    return Quaternion(w + value, x + value, y + value, z + value);
}


Quaternion Quaternion:: operator-(int value) {
    return Quaternion(w - value, x - value, y - value, z - value);
}


Quaternion Quaternion:: operator-(float value) {
    return Quaternion(w - value, x - value, y - value, z - value);
}

Quaternion Quaternion::operator*(const Quaternion& value) {
    double result_w = w * value.w - x * value.x - y * value.y - z * value.z;
    double result_x = w * value.x + x * value.w + y * value.z - z * value.y;
    double result_y = w * value.y - x * value.z + y * value.w + z * value.x;
    double result_z = w * value.z + x * value.y - y * value.x + z * value.w;
    return Quaternion(result_w, result_x, result_y, result_z);
}
Quaternion Quaternion:: operator*(int value) {
    return Quaternion(w * value, x * value, y * value, z * value);
}

Quaternion Quaternion:: operator*(float value) {
    return Quaternion(w * value, x * value, y * value, z * value);
}

std::string Quaternion::toString() {
    std::stringstream ss;
    ss << "(" << w << ", " << x << ", " << y << ", " << z << ")" << std::endl;
    return ss.str();
}
