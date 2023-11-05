#include "Matrix2x2.h"

Matrix2x2::Matrix2x2()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			elements[i][j] = 0;
		}
	}

	size[0] = 2;
	size[1] = 2;
}

Matrix2x2::Matrix2x2(float a00, float a01, float a10, float a11)
{
	elements[0][0] = a00;
	elements[0][1] = a01;
	elements[1][0] = a10;
	elements[1][1] = a11;

	size[0] = 2;
	size[1] = 2;
}

Matrix2x2::Matrix2x2(float diagonal)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
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

	size[0] = 2;
	size[1] = 2;
}


void Matrix2x2::transpose()
{
	Matrix2x2* tmp = new Matrix2x2();
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

float Matrix2x2::det() const
{
	return elements[0][0] * elements[1][1] - elements[1][0] * elements[0][1];
}

void Matrix2x2::adjoint()
{
	Matrix2x2* return_value = new Matrix2x2();

	return_value->elements[0][0] = elements[1][1];
	return_value->elements[0][1] = -elements[0][1];
	return_value->elements[1][0] = -elements[1][0];
	return_value->elements[1][1] = elements[0][0];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			elements[i][j] = return_value->elements[i][j];
		}
	}

	delete return_value;
}

void Matrix2x2::invert()
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

std::string Matrix2x2::toString()
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


Matrix2x2 Matrix2x2::matmul(const Matrix2x2& A, const Matrix2x2& B)
{
	Matrix2x2 return_value = Matrix2x2();

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

Matrix2x2 Matrix2x2::adjointThis(const Matrix2x2& A)
{
	Matrix2x2 return_value = Matrix2x2();

	return_value.elements[0][0] = A.elements[1][1];
	return_value.elements[0][1] = -A.elements[0][1];
	return_value.elements[1][0] = -A.elements[1][0];
	return_value.elements[1][1] = A.elements[0][0];

	return return_value;
}


Matrix2x2 Matrix2x2::operator+(const int& value)
{
	Matrix2x2 return_value = Matrix2x2();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] + value;
		}
	}
	return return_value;
}

Matrix2x2 Matrix2x2::operator-(const int& value)
{
	Matrix2x2 return_value = Matrix2x2();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] - value;
		}
	}
	return return_value;
}

Matrix2x2 Matrix2x2::operator*(const int& value)
{
	Matrix2x2 return_value = Matrix2x2();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] * value;
		}
	}
	return return_value;
}

Matrix2x2 Matrix2x2::operator+(const float& value)
{
	Matrix2x2 return_value = Matrix2x2();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] + value;
		}
	}
	return return_value;
}

Matrix2x2 Matrix2x2::operator-(const float& value)
{
	Matrix2x2 return_value = Matrix2x2();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] - value;
		}
	}
	return return_value;
}

Matrix2x2 Matrix2x2::operator*(const float& value)
{
	Matrix2x2 return_value = Matrix2x2();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] * value;
		}
	}
	return return_value;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& value)
{
	Matrix2x2 return_value = Matrix2x2();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] + value.elements[i][j];
		}
	}
	return return_value;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& value)
{
	Matrix2x2 return_value = Matrix2x2();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] - value.elements[i][j];
		}
	}
	return return_value;
}
