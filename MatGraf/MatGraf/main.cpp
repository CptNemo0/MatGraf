#include "Vector.hpp"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
using namespace std;

int main()
{
	Matrix4x4 A = Matrix4x4(1, 1, 1, -1,
						    1, 1, -1, 1,
		                    1, -1, 1, 1,
							-1, 1, 1, 1);

	Matrix4x4 B = Matrix4x4(2, 2, 2, -2,
							2, 2, -2, 2,
							2, -2, 2, 2,
							-2, 2, 2, 2);

	Matrix4x4 C = Matrix4x4(1, 2, 3, 4,
							5, 6, 7, 8,
							1, 2, 3, 4,
							5, 6, 7, 8);

	cout << "A: \n" << A.toString() << "\n";
	cout << "B: \n" << B.toString() << "\n";
	

	A = A + 5;
	cout << "A = A + 5\n" << A.toString() << "\n";

	A = A - 3;
	cout << "A = A - 3\n" << A.toString() << "\n";

	A = A * 2;
	cout << "A = A * 2\n" << A.toString() << "\n";

	A = A + B;
	cout<<"A = A + B\n" << A.toString() << "\n";

	A = A - B;
	cout << "A = A - B\n" << A.toString() << "\n";

	A.invert();
	cout << "A.invert()\n" << A.toString() << "\n";

	A.invert();
	cout << "A.invert()\n" << A.toString() << "\n";

	cout << "C: \n" << C.toString() << "\n";

	C.transpose();
	cout<< "C.transpose()\n" << C.toString() << "\n";

	C.transpose();
	cout << "C.transpose()\n" << C.toString() << "\n";

	cout << "matmul(A, C)\n" << Matrix4x4::matmul(A, C).toString() << "\n";
	cout << "matmul(C, A)\n" << Matrix4x4::matmul(C, A).toString() << "\n";

	Vector D = Vector(0.0f, 3.0f, 1.0f);
	Matrix4x4 E = Matrix4x4(1.0f);
	cout << D.toString() << "\n";
	cout << "E:\n" << E.toString() << "\n";

	E.SetScale(D);
	cout << "E.SetScale(D)\n" << E.toString() << "\n";
	
	Vector F = Vector(5.0f, 4.0f, 3.0f);
	Matrix4x4 G = Matrix4x4(1.0f);
	cout << F.toString() << "\n";
	cout << "G:\n" << G.toString() << "\n";

	G.SetTranslation(F);
	cout << "G.SetTranslation(F)\n" << G.toString() << "\n";

	vector<float> H{ 1, 0, 0, 1 };
	cout << "H: ";
	for (int i = 0; i < H.size(); i++)
	{
		cout << H[i] << " ";
	}
	cout << "\n";

	
	vector<float> J = Matrix4x4::RotateY(90.0, H);
	cout << "Matrix4x4::RotateY(90.0, H)" << "\n";
	cout << "H: ";
	for (int i = 0; i < J.size(); i++)
	{
		cout << J[i] << " ";
	}
	cout << "\n";

	float dot = 0.0f;
	for (int i = 0; i < 4; i++)
	{
		dot += J[i] * H[i];
	}

	float magH = 0.0f;
	for (int i = 0; i < 4; i++)
	{
		magH += H[i] * H[i];
	}
	magH = sqrtf(magH);

	float magJ = 0.0f;
	for (int i = 0; i < 4; i++)
	{
		magJ += J[i] * J[i];
	}
	magJ = sqrtf(magJ);

	cout << "Angle: " << acos(dot / (magH * magJ));
}

