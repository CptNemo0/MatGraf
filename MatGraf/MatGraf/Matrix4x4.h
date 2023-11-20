#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Matrix3x3.h"
#include <vector>
#include "Vector.hpp"
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI


class Matrix4x4
{
public:
	float elements[4][4];
	float size[2];

	Matrix4x4();
	Matrix4x4(float a00, float a01, float a02, float a03, 
			  float a10, float a11, float a12, float a13,
			  float a20, float a21, float a22, float a23,
			  float a30, float a31, float a32, float a33);

	Matrix4x4(float diagonal);

	void transpose();
	float det() const;
	void invert();
	void adjoint();
	Matrix3x3 minor(int row, int col);
	void SetScale(const Vector& scaleFactor);
	void SetTranslation(const Vector& translation);
	static std::vector<float> RotateY(const double angle, std::vector<float>& vector);
	static Matrix4x4 matmul(const Matrix4x4& A, const Matrix4x4& B);

	static std::vector<float> matmul(const Matrix4x4& A, const std::vector<float>& vB);

	std::string toString();

	Matrix4x4 operator+(const int& value);
	Matrix4x4 operator-(const int& value);
	Matrix4x4 operator*(const int& value);

	Matrix4x4 operator+(const float& value);
	Matrix4x4 operator-(const float& value);
	Matrix4x4 operator*(const float& value);

	Matrix4x4 operator+(const Matrix4x4& value);
	Matrix4x4 operator-(const Matrix4x4& value);
};