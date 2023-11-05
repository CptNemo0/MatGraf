#include "Matrix3x3.h"

Matrix3x3::Matrix3x3()
{
	size[0] = 3;
	size[1] = 3;

	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			elements[i][j] = 0;
		}
	}
}

Matrix3x3::Matrix3x3(float a00, float a01, float a02, float a10, float a11, float a12, float a20, float a21, float a22)
{
	size[0] = 3;
	size[1] = 3;

	elements[0][0] = a00; elements[0][1] = a01; elements[0][2] = a02;
	elements[1][0] = a10; elements[1][1] = a11; elements[1][2] = a12;
	elements[2][0] = a20; elements[2][1] = a21; elements[2][2] = a22;
	
	
}

Matrix3x3::Matrix3x3(float diagonal)
{
	size[0] = 3;
	size[1] = 3;

	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			if (i == j)
			{
				elements[i][j] = diagonal;
			}
			else
			{
				elements[i][j] = 0;
			}	
		}
	}
}

void Matrix3x3::transpose()
{
	Matrix3x3* tmp = new Matrix3x3();
	for (int i = 0; i < size[0]; ++i)
	{
		for (int j = 0; j < size[1]; ++j)
		{
			tmp->elements[j][i] = elements[i][j];
		}
	}

	for (int i = 0; i < size[0]; ++i)
	{
		for (int j = 0; j < size[1]; ++j)
		{
			elements[i][j] = tmp->elements[i][j];
		}
	}

	delete tmp;
}

float Matrix3x3::det() const
{
	float return_value = 0.0f;

	Matrix2x2* m1 = new Matrix2x2(elements[1][1], elements[1][2], elements[2][1], elements[2][2]);
	Matrix2x2* m2 = new Matrix2x2(elements[1][0], elements[1][2], elements[2][0], elements[2][2]);
	Matrix2x2* m3 = new Matrix2x2(elements[1][0], elements[1][1], elements[2][0], elements[2][1]);

	float det1 = m1->det();
	float det2 = m2->det();
	float det3 = m3->det();

	return_value = elements[0][0] * det1 - elements[0][1] * det2 + elements[0][2] * det3;

	delete m1, m2, m3;

	return return_value;
}

void Matrix3x3::adjoint()
{
	Matrix2x2* a00 = new Matrix2x2(elements[1][1], elements[1][2], elements[2][1], elements[2][2]);
	Matrix2x2* a01 = new Matrix2x2(elements[1][0], elements[1][2], elements[2][0], elements[2][2]);
	Matrix2x2* a02 = new Matrix2x2(elements[1][0], elements[1][1], elements[2][0], elements[2][1]);

	Matrix2x2* a10 = new Matrix2x2(elements[0][1], elements[0][2], elements[2][1], elements[2][2]);
	Matrix2x2* a11 = new Matrix2x2(elements[0][0], elements[0][2], elements[2][0], elements[2][2]);
	Matrix2x2* a12 = new Matrix2x2(elements[0][0], elements[0][1], elements[2][0], elements[2][1]);

	Matrix2x2* a20 = new Matrix2x2(elements[0][1], elements[0][2], elements[1][1], elements[1][2]);
	Matrix2x2* a21 = new Matrix2x2(elements[0][0], elements[0][2], elements[1][0], elements[1][2]);
	Matrix2x2* a22 = new Matrix2x2(elements[0][0], elements[0][1], elements[1][0], elements[1][1]);

	elements[0][0] = a00->det();
	elements[0][1] = a01->det();
	elements[0][2] = a02->det();

	elements[1][0] = a10->det();
	elements[1][1] = a11->det();
	elements[1][2] = a12->det();

	elements[2][0] = a20->det();
	elements[2][1] = a21->det();
	elements[2][2] = a22->det();

	transpose();

	delete a00, a01, a02,   a10, a11, a12,   a20, a21, a22;
}

void Matrix3x3::invert()
{
	float det_ = det();

	if (det_ != 0)
	{
		float inv_det = 1 / det_;

		adjoint();

		for (int i = 0; i < size[0]; i++)
		{
			for (int j = 0; j < size[1]; j++)
			{
				elements[i][j] *= inv_det;
			}
		}
	}
}


Matrix3x3 Matrix3x3::matmul(const Matrix3x3& A, const Matrix3x3& B)
{
	Matrix3x3 return_value = Matrix3x3();

	if (A.size[1] == B.size[0])
	{
		for (int i = 0; i < A.size[0]; i++)
		{
			for (int j = 0; j < B.size[1]; j++)
			{
				for (int k = 0; k < A.size[1]; k++)
				{
					return_value.elements[i][j] += A.elements[i][k] * B.elements[k][j];
				}
			}
		}
	}

	return return_value;
}

std::string Matrix3x3::toString()
{
	std::stringstream ss;

	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			ss << elements[i][j] << " " << std::setw(5);
		}
		ss << "\n";
	}
	ss << "\n";

	return ss.str();
}

Matrix3x3 Matrix3x3::operator+(const int& value)
{
	Matrix3x3 return_value = Matrix3x3();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] + value;
		}
	}
	return return_value;
}

Matrix3x3 Matrix3x3::operator-(const int& value)
{
	Matrix3x3 return_value = Matrix3x3();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] - value;
		}
	}
	return return_value;
}

Matrix3x3 Matrix3x3::operator*(const int& value)
{
	Matrix3x3 return_value = Matrix3x3();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] * value;
		}
	}
	return return_value;
}


Matrix3x3 Matrix3x3::operator+(const float& value)
{
	Matrix3x3 return_value = Matrix3x3();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] + value;
		}
	}
	return return_value;
}

Matrix3x3 Matrix3x3::operator-(const float& value)
{
	Matrix3x3 return_value = Matrix3x3();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] - value;
		}
	}
	return return_value;
}

Matrix3x3 Matrix3x3::operator*(const float& value)
{
	Matrix3x3 return_value = Matrix3x3();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] * value;
		}
	}
	return return_value;
}


Matrix3x3 Matrix3x3::operator+(const Matrix3x3& value)
{
	Matrix3x3 return_value = Matrix3x3();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] + value.elements[i][j];
		}
	}
	return return_value;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& value)
{
	Matrix3x3 return_value = Matrix3x3();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] - value.elements[i][j];
		}
	}
	return return_value;
}