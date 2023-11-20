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
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			tmp->elements[i][j] = elements[i][j];
		}
	}

	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			elements[i][j] = tmp->elements[j][i];
		}
	}

	delete tmp;
}

float Matrix4x4::det() const
{
	float return_value = 0;

	Matrix3x3 m1 = Matrix3x3(elements[1][1], elements[1][2], elements[1][3],
							 elements[2][1], elements[2][2], elements[2][3],
							 elements[3][1], elements[3][2], elements[3][3]);

	Matrix3x3 m2 = Matrix3x3(elements[0][1], elements[0][2], elements[0][3],
							 elements[2][1], elements[2][2], elements[2][3],
		                     elements[3][1], elements[3][2], elements[3][3]);

	Matrix3x3 m3 = Matrix3x3(elements[0][1], elements[0][2], elements[0][3],
		                     elements[1][1], elements[1][2], elements[1][3],
						     elements[3][1], elements[3][2], elements[3][3]);

	Matrix3x3 m4 = Matrix3x3(elements[0][1], elements[0][2], elements[0][3],
						     elements[1][1], elements[1][2], elements[1][3],
							 elements[2][1], elements[2][2], elements[2][3]);

	Matrix3x3 matrices[] { m1, m2, m3, m4 };

	int sign = 1;

	for (int i = 0; i < 4; i++)
	{
		return_value += sign * elements[i][0] * matrices[i].det();
		sign = -sign;
	}
	return return_value;
}
void Matrix4x4::adjoint()
{
	Matrix4x4* tmp = new Matrix4x4();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Matrix3x3 m = minor(i, j);
			tmp->elements[i][j] = m.det() * powf(-1, (i + j));
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elements[i][j] = tmp->elements[i][j];
		}
	}

	delete tmp;
}

Matrix3x3 Matrix4x4::minor(int row, int col)
{
	Matrix3x3 minor = Matrix3x3();

	std::vector<float> elements_v;

	for (int i = 0; i < 4; i++)
	{
		if (i != row)
		{
			for (int j = 0; j < 4; j++)
			{
				if (j != col)
				{
					elements_v.push_back(elements[i][j]);
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			minor.elements[i][j] = elements_v[i * 3 + j];
		}
	}

	return minor;
}

void Matrix4x4::SetScale(const Vector& scaleFactor)
{
	elements[0][0] *= scaleFactor.getX();
	elements[1][1] *= scaleFactor.getY();
	elements[2][2] *= scaleFactor.getZ();
}

void Matrix4x4::SetTranslation(const Vector& translation)
{
	elements[0][3] = translation.getX();
	elements[1][3] = translation.getY();
	elements[2][3] = translation.getZ();
}

std::vector<float> Matrix4x4::RotateY(const double angle, std::vector<float>& vector) {
	float sinAngle = (float)sin(M_PI * angle / 180);
	float cosAngle = (float)cos(M_PI * angle / 180);

	float rotationMatrix[4][4] = {
			{cosAngle, 0, sinAngle, 0},
			{0, 1, 0, 0},
			{-sinAngle, 0, cosAngle, 0},
			{0, 0, 0, 1}
	};

	Matrix4x4 rotation_matrix = Matrix4x4(cosAngle, 0.0f, sinAngle, 0.0f,
										      0.0f, 1.0f,     0.0f, 0.0f,
										 -sinAngle, 0.0f, cosAngle, 0.0f,
	                                          0.0f, 0.0f,     0.0f, 1.0f);

	return Matrix4x4::matmul(rotation_matrix, vector);;
}

void Matrix4x4::invert()
{
	float det_internal = det();

	if (det_internal != 0)
	{
		adjoint();

		float inv_det = 1 / det_internal;

		for (int i = 0; i < size[0]; i++)
		{
			for (int j = 0; j < size[1]; j++)
			{
				elements[i][j] *= inv_det;
			}
		}
	}
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

std::vector<float> Matrix4x4::matmul(const Matrix4x4& A, const std::vector<float>& B)
{
	std::vector<float> return_value = std::vector<float>();
	return_value.resize(4);

	return_value[0] = 0;
	return_value[1] = 0;
	return_value[2] = 0;
	return_value[3] = 0;

	if (A.size[1] == B.size())
	{
		for (int i = 0; i < A.size[0]; i++)
		{
			for (int j = 0; j < B.size(); j++)
			{
				for (int k = 0; k < A.size[1]; k++)
				{
					return_value[k] += A.elements[i][k] * B[j];
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