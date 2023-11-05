#include "Vector.hpp"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
using namespace std;

int main()
{
	Matrix3x3 m = Matrix3x3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
	Matrix3x3 n = Matrix3x3(2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 1.0f);

	Matrix3x3 z = Matrix3x3::matmul(m, n);

	std::cout << z.toString();

	std::cout<<m.toString();

	m = m + 1;

	std::cout << m.toString();

	m = m - 1;

	std::cout << m.toString();

	m = m * 2;

	std::cout << m.toString();

	m.transpose();

	std::cout << m.toString();

	m.invert();

	std::cout<< "invereted\n" << m.toString();

	m = m + n;

	std::cout << m.toString();

	m = m - n;

	std::cout << m.toString();
}

