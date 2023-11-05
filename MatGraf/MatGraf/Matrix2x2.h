#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Matrix2x2
{
public:
	float elements[2][2];
	float size[2];

	Matrix2x2();
	Matrix2x2(float a00, float a01, float a10, float a11);
	Matrix2x2(float diagonal);
	
	void transpose();
	float det() const;
	void invert();
	void adjoint();

	static Matrix2x2 matmul(const Matrix2x2& A, const Matrix2x2& B);
	static Matrix2x2 adjointThis(const Matrix2x2& A);

	std::string toString();

	Matrix2x2 operator+(const int& value);
	Matrix2x2 operator-(const int& value);
	Matrix2x2 operator*(const int& value);

	Matrix2x2 operator+(const float& value);
	Matrix2x2 operator-(const float& value);
	Matrix2x2 operator*(const float& value);

	Matrix2x2 operator+(const Matrix2x2& value);
	Matrix2x2 operator-(const Matrix2x2& value);
};

