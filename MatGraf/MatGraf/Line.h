#pragma once
#include <iostream>
#include<cmath>
#include<string>
#include <sstream>
#include "Vector.hpp"

class Line
{
public:
	Vector p;
	Vector v;

	Line(const Vector& new_p, const Vector& new_v);
	Line(Vector point_1, Vector point_2, bool a);

	Vector SamplePoint();
	Vector SampleVector();
	Vector GetPoint(float t);
	static Vector GetIntersectionPoint(Line line_1, Line line_2);
	static float Angle(Line line_1, Line line_2);
	std::string toString();
};