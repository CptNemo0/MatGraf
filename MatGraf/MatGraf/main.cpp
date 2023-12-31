#include "Vector.hpp"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Line.h"
#include "Plane.h"
#include "iostream"
#include <chrono>
#include <thread>
using namespace std;

const int RESOLUTION_X = 15;
const int RESOLUTION_Y = 15;
const int RESOLUTION_Z = 15;

constexpr int X_OFFSET = RESOLUTION_X / 2;
constexpr int Y_OFFSET = RESOLUTION_Y / 2;
constexpr int Z_OFFSET = RESOLUTION_Z / 2;

const int GRID_RESOLUTION = 60;

const int CAMERA_Z = -50;

int ROTATION_INC = 1;
const float SCALE_INC = 1.25f;


struct Face
{
	vector<Vector> vertices;

	Face(const Vector& a, const Vector& b, const Vector& c, const Vector& d)
	{
		this->vertices = vector<Vector>();
		vertices.push_back(a);
		vertices.push_back(b);
		vertices.push_back(c);
		vertices.push_back(d);
	}
};

struct Point
{
	int x, y;

	Point()
	{
		Point(0.0f, 0.0f);
	}
	Point(float new_x, float new_y) : x(new_x), y(new_y){}
	Point(const Vector& b)
	{
		this->x = b.x;
		this->y = b.y;
	}
};

bool is_in_quad(Point point, Face polygon)
{
	int pos = 0;
	int neg = 0;
	for (int i = 0; i < polygon.vertices.size(); i++)
	{
		auto p1 = polygon.vertices[i];
		auto p2 = polygon.vertices[(i + 1) % 4];

		auto a = -(p2.y - p1.y);
		auto b = p2.x - p1.x;
		auto c = -(a * p1.x + b * p1.y);

		auto d = a * point.x + b * point.y + c;

		if (d < 0)
		{
			pos++;
		}
		else if (d > 0)
		{
			neg++;
		}
	}

	if (pos > 0 && neg == 0)
	{
		return true;
	}
	else if (pos == 0 && neg > 0)
	{
		return true;
	}
	else if(pos > 0 && neg > 0)
	{
		return false;
	}

}

int main()
{	
	std::chrono::milliseconds timespan(16); // or whatever

	float idx = 0;

	Point grid[GRID_RESOLUTION][GRID_RESOLUTION];

	for (int i = 0; i < GRID_RESOLUTION; i++)
	{
		for (int j = 0; j < GRID_RESOLUTION; j++)
		{
			grid[i][j] = Point(i - GRID_RESOLUTION * 0.5f, j - GRID_RESOLUTION * 0.5f);
		}
	}

	Vector tl_f = Vector(-15.0f, 15.0f, -15.0f);
	Vector bl_f = Vector(-15.0f, -15.0f, -15.0f);
	Vector br_f = Vector(15.0f, -15.0f, -15.0f);
	Vector tr_f = Vector(15.0f , 15.0f, -15.0f);
	
	Vector tl_b = Vector(-15.0f, 15.0f, 15.0f);
	Vector bl_b = Vector(-15.0f, -15.0f, 15.0f);
	Vector br_b = Vector(15.0f, -15.0f, 15.0f);
	Vector tr_b = Vector(15.0f, 15.0f, 15.0f);

	//Vector vertices[8]{ tl_f, tr_f, bl_f, br_f, tl_b, tr_b, bl_b, br_b };
	//vector<Vector> vertices {tl_f, tr_f, bl_f, br_f, tl_b, tr_b, bl_b, br_b};

	while (true)
	{
		//cout << tl_f.toString() << endl;
		Face front_face = Face(tl_f, bl_f, br_f, tr_f);
		Face right_face = Face(tr_f, br_f, br_b, tr_b);

		Face back_face = Face(tl_b, bl_b, br_b, tr_b);

		Face top_face = Face(tl_b, tl_f, tr_f, tr_b);
		Face bot_face = Face(bl_b, bl_f, br_f, br_b);

		
		Face left_face = Face(tl_f, bl_f, bl_b, tl_f);

		vector<Face> faces{ front_face, back_face, top_face, bot_face, right_face, left_face };

		string output = "";

		for (int i = 0; i < GRID_RESOLUTION; i++)
		{
			for (int j = 0; j < GRID_RESOLUTION; j++)
			{
				string sign = " . ";

				for (auto& face : faces)
				{
					if (is_in_quad(grid[i][j], face))
					{
						sign = " 0 ";
						break;
					}
				}

				output += sign;
			}

			output += "\n";
		}
		system("CLS");
		cout << output << endl;
		std::this_thread::sleep_for(timespan);

		Vector::RotateY(tl_f, ROTATION_INC);
		Vector::RotateY(bl_f, ROTATION_INC);
		Vector::RotateY(br_f, ROTATION_INC);
		Vector::RotateY(tr_f, ROTATION_INC);

		Vector::RotateY(tl_b, ROTATION_INC);
		Vector::RotateY(bl_b, ROTATION_INC);
		Vector::RotateY(br_b, ROTATION_INC);
		Vector::RotateY(tr_b, ROTATION_INC);

		Vector::RotateX(tl_f, ROTATION_INC);
		Vector::RotateX(bl_f, ROTATION_INC);
		Vector::RotateX(br_f, ROTATION_INC);
		Vector::RotateX(tr_f, ROTATION_INC);

		Vector::RotateX(tl_b, ROTATION_INC);
		Vector::RotateX(bl_b, ROTATION_INC);
		Vector::RotateX(br_b, ROTATION_INC);
		Vector::RotateX(tr_b, ROTATION_INC);

		Vector::RotateZ(tl_f, ROTATION_INC);
		Vector::RotateZ(bl_f, ROTATION_INC);
		Vector::RotateZ(br_f, ROTATION_INC);
		Vector::RotateZ(tr_f, ROTATION_INC);

		Vector::RotateZ(tl_b, ROTATION_INC);
		Vector::RotateZ(bl_b, ROTATION_INC);
		Vector::RotateZ(br_b, ROTATION_INC);
		Vector::RotateZ(tr_b, ROTATION_INC);


		
		/*char a;

		cin >> a;

		switch (a)
		{
		case 'a':
			Vector::RotateY(tl_f, -ROTATION_INC);
			Vector::RotateY(bl_f, -ROTATION_INC);
			Vector::RotateY(br_f, -ROTATION_INC);
			Vector::RotateY(tr_f, -ROTATION_INC);

			Vector::RotateY(tl_b, -ROTATION_INC);
			Vector::RotateY(bl_b, -ROTATION_INC);
			Vector::RotateY(br_b, -ROTATION_INC);
			Vector::RotateY(tr_b, -ROTATION_INC);
			continue;
			break;

		case 'd':
			Vector::RotateY(tl_f, ROTATION_INC);
			Vector::RotateY(bl_f, ROTATION_INC);
			Vector::RotateY(br_f, ROTATION_INC);
			Vector::RotateY(tr_f, ROTATION_INC);

			Vector::RotateY(tl_b, ROTATION_INC);
			Vector::RotateY(bl_b, ROTATION_INC);
			Vector::RotateY(br_b, ROTATION_INC);
			Vector::RotateY(tr_b, ROTATION_INC);
			continue;
			break;

		case 'w':
			Vector::RotateX(tl_f, ROTATION_INC);
			Vector::RotateX(bl_f, ROTATION_INC);
			Vector::RotateX(br_f, ROTATION_INC);
			Vector::RotateX(tr_f, ROTATION_INC);

			Vector::RotateX(tl_b, ROTATION_INC);
			Vector::RotateX(bl_b, ROTATION_INC);
			Vector::RotateX(br_b, ROTATION_INC);
			Vector::RotateX(tr_b, ROTATION_INC);
			continue;
			break;

		case 's':
			Vector::RotateX(tl_f, -ROTATION_INC);
			Vector::RotateX(bl_f, -ROTATION_INC);
			Vector::RotateX(br_f, -ROTATION_INC);
			Vector::RotateX(tr_f, -ROTATION_INC);

			Vector::RotateX(tl_b, -ROTATION_INC);
			Vector::RotateX(bl_b, -ROTATION_INC);
			Vector::RotateX(br_b, -ROTATION_INC);
			Vector::RotateX(tr_b, -ROTATION_INC);
			continue;
			break;
		}*/
	}
}

