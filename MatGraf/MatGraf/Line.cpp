#include "Line.h"
#include <iostream>
Line::Line(const Vector& new_p, const Vector& new_v) : p(new_p), v(new_v) {}

Line::Line(Vector point_1, Vector point_2, bool a)
{
	this->p = point_1;
	this->v = point_2 - point_1;
}

Vector Line::SamplePoint()
{
	int t = rand() & 100;
	float z = (float)t;
	return p + v * z;
}

Vector Line::SampleVector()
{
	Vector point_1 = SamplePoint();
	Vector point_2 = SamplePoint();
	
	Vector new_vector = point_2 - point_1;
	//new_vector.normalize();

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

	Vector difference = line_2.p - line_1.p;
	Vector cross_product_dif_v2 = Vector::cross(difference, line_2.v);
	Vector cross_product_v1_v2 = Vector::cross(line_1.v, line_2.v);

	float t_1_top = Vector::dot(cross_product_dif_v2, cross_product_v1_v2);
	float t_1_bot = Vector::dot(cross_product_v1_v2, cross_product_v1_v2);
	t_1 = t_1_top / t_1_bot;
	Vector cross_product_v2_v1 = Vector::cross(line_2.v, line_1.v);

	Vector cross_product_dif_v1 = Vector::cross(difference, line_1.v);
		
	t_2 = -1.0f * Vector::dot(cross_product_dif_v1, cross_product_v2_v1) / Vector::dot(cross_product_v2_v1, cross_product_v2_v1);

	Vector line_1_t_1 = line_1.GetPoint(t_1);
	Vector line_2_t_2 = line_2.GetPoint(t_2);

	Vector n = line_2_t_2 - line_1_t_1;

	if (n.getMagnitude() == 0)
	{
		return line_2_t_2;
	}
	else
	{
		std::cout << "LINES DO NOT INTERSECT!!!!" << std::endl;
		return Vector(0.0f, 0.0f, 0.0f);
	}
}

float Line::Angle(Line line_1, Line line_2)
{
	Vector line_1_vector = line_1.SampleVector();
	Vector line_2_vector = line_2.SampleVector();

	float angle = Vector::angle(line_1_vector, line_2_vector);

	angle = angle * 180 / 3.1415f;

	

	return angle;
}

std::string Line::toString()
{
	std::stringstream ss;
	ss << "Line: p: " << p.toString() << ", v: " << v.toString();
	return ss.str();
}

std::vector<Vector> Line::IntersectionSphere(Line l, Vector center, float radius)
{
	std::vector<Vector> intersections = std::vector<Vector>();
	Vector old_v = l.v;
	l.v.normalize();
	Vector normalized_v = l.v;
	l.v = old_v;

	Vector w = center - l.p;

	float L = Vector::dot(w, normalized_v);
	float e_mag = l.p.getMagnitude();

	Vector P = l.p + (normalized_v * (L + e_mag));
	intersections.push_back(P);

	float p_t = (P - l.p).x / l.v.x;
	std::cout << p_t << std::endl;

	float t_positive = p_t + 1.0f;
	float t_negative = p_t - 1.0f;

	auto positive_v = l.p + l.v * t_positive;
	auto negative_v = l.p + l.v * t_negative;
	
	int sign = 1;
	float increment = 0.0001;
	float epsilon = 0.01;
	float new_t = p_t;
	if (Vector::distance(center, positive_v) > Vector::distance(center, negative_v))
	{
		sign = -1.0f;
	}
	
	while (true)
	{
		new_t += increment;

		auto point = l.p + l.v * sign * new_t;

		auto distance = point.x * point.x + point.y * point.y + point.z * point.z;
		if (abs(distance - radius * radius) < epsilon)
		{
			intersections.push_back(point);
			break;
		}
	}

	//intersections.push_back(Z);
	return intersections;
}




