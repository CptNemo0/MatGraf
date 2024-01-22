#include "Plane.h"

Plane::Plane(float new_A, float new_B, float new_C, float new_D) : A(new_A), B(new_B), C(new_C), D(new_D)
{
}

Vector Plane::GetNormal()
{
    Vector normal = Vector(A, B, C);
    normal.normalize();
    return normal;
}

Vector Plane::SamplePoint()
{
    return Vector(0.0f, 0.0f, - 1.0f * D / C);
}

Line Plane::IntersectionLine(Plane plane_1, Plane plane_2)
{
    Vector n_1 = plane_1.GetNormal();
    Vector n_2 = plane_2.GetNormal();

    Vector cross_product = Vector::cross(n_1, n_2);

    Vector Q_1 = plane_1.SamplePoint();
    Vector Q_2 = plane_2.SamplePoint();

    float bot = n_2.x - (n_1.x * n_2.y / n_1.y);
    float x, y;
    if (n_1.y != 0 && bot != 0)
    {
        x = ( (Vector::dot(n_2, Q_2) -  ( ( n_2.y * (Vector::dot(n_1, Q_1) ) / n_1.y)  ))/ bot);
        y = ( (Vector::dot(n_1, Q_1) - n_1.x) / n_1.y );
    }

    //(1, -6, 0) + t*(-0.320256, 0.160128, 0.800641)

    return Line(Vector(x, y, 0.0f), cross_product);
}

float Plane::AnglePlaneLine(Plane plane, Line line)
{
    Vector line_Vector = line.SampleVector();
    Vector normal = plane.GetNormal();

    float angle = Vector::angle(line_Vector, normal);
    angle = angle * 180 / 3.1415f;
    if (angle > 90)
    {
        angle = 90 - angle;
    }

    return fabs(angle);
}

float Plane::Angle(Plane plane_1, Plane plane_2)
{
    Vector normal_1 = plane_1.GetNormal();
    Vector normal_2 = plane_2.GetNormal();

    float angle = Vector::angle(normal_1, normal_2);

    angle = angle * 180 / 3.1415f;
    if (angle > 90)
    {
        angle = 90 - angle;
    }

    return fabs(angle);
}

Vector Plane::IntersectionWithLine(Plane plane, Line line)
{
    float t = 0.0f;

    Vector q = plane.SamplePoint();
    Vector p = line.p;
    Vector v = line.v;
    Vector n = plane.GetNormal();
   
    t = Vector::dot(n * -1.0f, (p - q)) / Vector::dot(n, v);

    Vector return_value = p + v * t;
    return return_value;
}

std::string Plane::toString()
{
    std::stringstream ss;
    ss << "Plane: A: " << A << ", B: " << B << ", C:" << C <<", D:"<<D;
    return ss.str();
}

