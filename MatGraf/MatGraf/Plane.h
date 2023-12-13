#pragma once

#include "Vector.hpp"
#include "Line.h"

class Plane
{
public:
	float A;
	float B;
	float C;
	float D;

	Plane(float new_A, float new_B, float new_C, float new_D);

	Vector GetNormal();
	Vector SamplePoint();
	static Line IntersectionLine(Plane plane_1, Plane plane_2);
	static float AnglePlaneLine(Plane plane, Line line);
	static float Angle(Plane plane_1, Plane plane_2);
	std::string toString();
};

