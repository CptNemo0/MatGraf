#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Matrix2x2.h"

class Matrix3x3
{
public:
	float elements[3][3];
	float size[2];

	Matrix3x3();
	Matrix3x3(float a00, float a01, float a02, float a10, float a11, float a12, float a20, float a21, float a22);
	Matrix3x3(float diagonal);

	void transpose();
	float det() const;
	void invert();
	void adjoint();

	static Matrix3x3 matmul(const Matrix3x3& A, const Matrix3x3& B);

	std::string toString();
	
	Matrix3x3 operator+(const int& value);
	Matrix3x3 operator-(const int& value);
	Matrix3x3 operator*(const int& value);

	Matrix3x3 operator+(const float& value);
	Matrix3x3 operator-(const float& value);
	Matrix3x3 operator*(const float& value);

	Matrix3x3 operator+(const Matrix3x3& value);
	Matrix3x3 operator-(const Matrix3x3& value);
};

