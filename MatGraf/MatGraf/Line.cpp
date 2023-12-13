#include "Line.h"

Line::Line(const Vector& new_p, const Vector& new_v) : p(new_p), v(new_v) {}

Line::Line(Vector point_1, Vector point_2, bool a)
{
	this->p = point_1;
	this->v = point_2 - point_1;
}

Vector Line::SamplePoint()
{
	int t = rand() & 100;

	return p + v * t;
}

Vector Line::SampleVector()
{
	Vector point_1 = SamplePoint();
	Vector point_2 = SamplePoint();
	
	Vector new_vector = point_2 - point_1;
	new_vector.normalize();

	return new_vector;
}

Vector Line::GetPoint(float t)
{
	return p + (v * t);
}

Vector Line::GetIntersectionPoint(Line line_1, Line line_2)
{
	float t_1 = 0.0f;
	float t_2 = 0.0f;

	Vector cross_product_v1_v2 = Vector::cross(line_1.v, line_2.v);
	Vector cross_product_v2_v1 = Vector::cross(line_2.v, line_1.v);

	Vector difference = line_2.p - line_1.p;

	Vector cross_product_dif_v1 = Vector::cross(difference, line_1.v);
	Vector cross_product_dif_v2 = Vector::cross(difference, line_2.v);


	t_1 = Vector::dot(cross_product_dif_v2, cross_product_v1_v2) / Vector::dot(cross_product_v1_v2, cross_product_v1_v2);
	t_2 = -1.0f * Vector::dot(cross_product_dif_v1, cross_product_v2_v1) / Vector::dot(cross_product_v2_v1, cross_product_v2_v1);

	Vector line_1_t_1 = line_1.GetPoint(t_1);
	Vector line_2_t_2 = line_2.GetPoint(t_2);

	Vector n = line_2_t_2 - line_1_t_1;

	Vector intersection = line_1_t_1 + n;

	return intersection;
}

float Line::Angle(Line line_1, Line line_2)
{
	Vector line_1_vector = line_1.SampleVector();
	Vector line_2_vector = line_2.SampleVector();

	std::cout << line_1_vector.toString() << std::endl;
	std::cout << line_2_vector.toString() << std::endl;

	float angle = Vector::angle(line_1_vector, line_2_vector);

	angle = angle * 180 / 3.1415f;

	if (angle > 90)
	{
		angle = 180.0f - angle;
	}

	return angle;
}

std::string Line::toString()
{
	std::stringstream ss;
	ss << "Line: p: " << p.toString() << ", v: " << v.toString();
	return ss.str();
}





