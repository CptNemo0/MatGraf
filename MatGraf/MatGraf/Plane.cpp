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
    return Vector(A, B, C) + rand() % 100;
}

Line Plane::IntersectionLine(Plane plane_1, Plane plane_2)
{
    Vector n_1 = plane_1.GetNormal();
    Vector n_2 = plane_2.GetNormal();

    Vector cross_product = Vector::cross(n_1, n_2);

    float x, y, z;

    z = 0.0f;

    Vector equation_1 = Vector(plane_1.A, plane_1.B, plane_1.D);
    Vector equation_2 = Vector(plane_2.A, plane_2.B, plane_2.D);

    if (equation_1.x != equation_2.x)
    {
        float d = equation_1.x / equation_2.x;
        equation_2 = equation_2 * d;
    }

    Vector equation_3 = equation_1 - equation_2;

    y = equation_3.z / equation_3.y;
    x = equation_1.z - y;

    Vector intersection_point = Vector(x, y, z);

    return Line(intersection_point, cross_product);
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

std::string Plane::toString()
{
    std::stringstream ss;
    ss << "Plane: A: " << A << ", B: " << B << ", C:" << C <<", D:"<<D;
    return ss.str();
}


