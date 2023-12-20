#include "Vector.hpp"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Line.h"
#include "Plane.h"
#include "iostream"
using namespace std;

int main()
{
	srand(time(NULL));

	Line line_1 = Line(Vector(3, 1, 5), Vector(-2, 5, 0));
	Line line_2 = Line(Vector(1, -5, 3), Vector(-2, 4, 0));
	
	cout << "line_1: " << line_1.toString() << endl;
	cout << "line_2: " << line_2.toString() << endl;

	Vector intersection = Line::GetIntersectionPoint(line_1, line_2);
	cout << "Intersection point: " << intersection.toString() << endl;

	float angle = Line::Angle(line_1, line_2);
	cout << "Angle between lines: " << angle << endl;

	Line line_3 = Line(Vector(-2, 2, -1), Vector(3, -1, 2));
	Plane plane_1 = Plane(2, 3, 3, -8);

	cout << "line_3: " << line_3.toString() << endl;
	cout << "plane_1: " << plane_1.toString() << endl;

	cout << "Angle between line_3 and plane_1: " << Plane::AnglePlaneLine(plane_1, line_3) << endl;
	
	Plane plane_2 = Plane(2, -1, 1, -8);
	Plane plane_3 = Plane(4, 3, 1, 14);

	cout << "plane_2: " << plane_2.toString() << endl;
	cout << "plane_3: " << plane_3.toString() << endl;

	Line intersection_line = Plane::IntersectionLine(plane_2, plane_3);
	cout << "Intersection line: " << intersection_line.toString() << endl;
	cout << "Angle between plane_2 and plane_3: " << Plane::Angle(plane_2, plane_3) << endl;
		
	Line line_4 = Line(Vector(5, 5, 4), Vector(10, 10, 6), true);
	Line line_5 = Line(Vector(5, 5, 5), Vector(10, 10, 3), true);
	cout << "line_4: " << line_4.toString() << endl;
	cout << "line_5: " << line_5.toString() << endl;
	Vector intersection_2 = Line::GetIntersectionPoint(line_4, line_5);
	cout << "Intersection point: " << intersection_2.toString() << endl;

	Line line_6 = Line(Vector(3, -1, -2), Vector(5, 3, -4), true);
	cout << "line)6" << line_6.toString() << endl;

	auto intersections = Line::IntersectionSphere(line_6, Vector(0.0f, 0.0f, 0.0f), sqrtf(26));
	for (Vector var : intersections)
	{
		cout << "Intersection point: " << var.toString() << endl;
	}



}//(3, -1, -2) + t*(2, 4, -2)

