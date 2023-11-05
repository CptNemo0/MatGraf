#include "Matrix4x4.h"

Matrix4x4::Matrix4x4()
{
	size[0] = 4;
	size[1] = 4;

	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			elements[i][j] = 0.0f;
		}
	}
}

Matrix4x4::Matrix4x4(float a00, float a01, float a02, float a03, float a10, float a11, float a12, float a13, float a20, float a21, float a22, float a23, float a30, float a31, float a32, float a33)
{
	size[0] = 4;
	size[1] = 4;

	elements[0][0] = a00; elements[0][1] = a01; elements[0][2] = a02; elements[0][3] = a03;

	elements[1][0] = a10; elements[1][1] = a11; elements[1][2] = a12; elements[1][3] = a13;
	
	elements[2][0] = a20; elements[2][1] = a21; elements[2][2] = a22; elements[2][3] = a23;
	
	elements[3][0] = a30; elements[3][1] = a31; elements[3][2] = a32; elements[3][3] = a33;
}

Matrix4x4::Matrix4x4(float diagonal)
{
	size[0] = 4;
	size[1] = 4;

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

void Matrix4x4::transpose()
{
	Matrix4x4* tmp = new Matrix4x4();
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

float Matrix4x4::det() const
{
	return 0.0f;
}



Matrix4x4 Matrix4x4::matmul(const Matrix4x4& A, const Matrix4x4& B)
{
	Matrix4x4 return_value = Matrix4x4();

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

std::string Matrix4x4::toString()
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

Matrix4x4 Matrix4x4::operator+(const int& value)
{
	Matrix4x4 return_value = Matrix4x4();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] + value;
		}
	}
	return return_value;
}

Matrix4x4 Matrix4x4::operator-(const int& value)
{
	Matrix4x4 return_value = Matrix4x4();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] - value;
		}
	}
	return return_value;
}

Matrix4x4 Matrix4x4::operator*(const int& value)
{
	Matrix4x4 return_value = Matrix4x4();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] * value;
		}
	}
	return return_value;
}

Matrix4x4 Matrix4x4::operator+(const float& value)
{
	Matrix4x4 return_value = Matrix4x4();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] + value;
		}
	}
	return return_value;
}

Matrix4x4 Matrix4x4::operator-(const float& value)
{
	Matrix4x4 return_value = Matrix4x4();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] - value;
		}
	}
	return return_value;
}

Matrix4x4 Matrix4x4::operator*(const float& value)
{
	Matrix4x4 return_value = Matrix4x4();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] * value;
		}
	}
	return return_value;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& value)
{
	Matrix4x4 return_value = Matrix4x4();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] + value.elements[i][j];
		}
	}
	return return_value;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& value)
{
	Matrix4x4 return_value = Matrix4x4();
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			return_value.elements[i][j] = elements[i][j] - value.elements[i][j];
		}
	}
	return return_value;
}