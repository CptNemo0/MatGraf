#include "Vector.hpp"

using namespace std;

int main()
{
    cout << "- - - - Vector test - - - -\n";

    Vector A = Vector();
    Vector B = Vector(1.0f, 2.0f, 3.0f);
    Vector C = Vector(4.0f, 5.0f, 6.0f);

    cout << "Vector A: " << A.toString() << "\n";
    cout << "Vector B: " << B.toString() << "\n";
    cout << "Vector C: " << C.toString() << "\n";

    cout << "A + B: " << (A + B).toString() << "\n";
    cout << "B + A: " << (B + A).toString() << "\n";

    cout << "A - B: " << (A - B).toString() << "\n";
    cout << "B - A: " << (B - A).toString() << "\n";

    cout << "C * B: " << (C * B).toString() << "\n";
    cout << "B * C: " << (B * C).toString() << "\n";

    cout << "C / B: " << (C / B).toString() << "\n";
    cout << "B / C: " << (B / C).toString() << "\n";

    Vector D = Vector(0.0f, 3.0f, 0.0f);
    Vector E = Vector(5.0f, 5.0f, 0.0f);

    cout << "Vector D: " << D.toString() << "\n";
    cout << "Vector E: " << E.toString() << "\n";
    cout << "Angle(D, E): " << Vector::angle(D, E) << " rad\n";
    cout << "Angle(E, D): " << Vector::angle(E, D) << " rad\n";

    Vector F = Vector(4.0f, 5.0f, 1.0f);
    Vector G = Vector(4.0f, 1.0f, 3.0f);
    Vector H = Vector::cross(F, G);

    cout << "Vector F: " << F.toString() << "\n";
    cout << "Vector G: " << G.toString() << "\n";
    cout << "Vector H: " << H.toString() << "\n";

    cout << "Angle(H, F): " << Vector::angle(H, F) << " rad\n";
    cout << "Angle(H, G): " << Vector::angle(H, G) << " rad\n";

    H.normalize();
    cout << "Normalize(H): " << H.toString() << " H magnitude: " << H.getMagnitude() << endl;
}

