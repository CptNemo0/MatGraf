#include "Vector.hpp"

Vector::Vector()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Vector::Vector(const float& new_x, const float& new_y, const float& new_z)
{
	this->x = new_x;
	this->y = new_y;
	this->z = new_z;
}

float Vector::getMagnitude() const
{
	return std::sqrt( (x * x) + (y * y) + (z * z) );
}

float Vector::inverseSqrtMagnitude() const
{
	float magnitude = getMagnitude();
	float retValue = -1;
	if (magnitude != 0)
	{
		retValue = sqrt(1.0f / magnitude);
	}
	return retValue;
}

void Vector::normalize()
{
	float invSqrtMagnitude = inverseSqrtMagnitude();
	this->x *= invSqrtMagnitude;
	this->y *= invSqrtMagnitude;
	this->z *= invSqrtMagnitude;
}

float Vector::getX() const
{
	return x;
}

float Vector::getY() const
{
	return y;
}

float Vector::getZ() const
{
	return z;
}

void Vector::setX(const float& value)
{
	this->x = value;
}

void Vector::setY(const float& value)
{
	this->y = value;
}

void Vector::setZ(const float& value)
{
	this->z = value;
}

void Vector::set(const float& new_x, const float& new_y, const float& new_z)
{
	this->x = new_x;
	this->y = new_y;
	this->z = new_z;
}

float Vector::dot(const Vector& w, const Vector& v)
{
	return ((w.getX() + v.getX()) + (w.getY() + v.getY()) + (w.getZ() + v.getZ()));
}

float Vector::angle(const Vector& from, const Vector& to)
{
	float dotProduct = Vector::dot(from, to);
	float invSqrtMagA = from.inverseSqrtMagnitude();
	float invSqrtMagB = to.inverseSqrtMagnitude();

	if (invSqrtMagA != -1 || invSqrtMagB != -1)
	{
		return -1;
	}

	double cosValue = dotProduct * invSqrtMagA * invSqrtMagA;
	cosValue = std::max(-1.0, std::min(1.0, cosValue));

	return (float) acos(cosValue) * (180.0 / M_PI);
}

Vector Vector::cross(const Vector& w, const Vector& v)
{
	Vector retValue = Vector ( (w.getX() * v.getX()), (w.getY() * v.getY()), (w.getZ() * v.getZ()) );
	return retValue;
}

float Vector::distance(const Vector& w, const Vector& v)
{
	float deltaX = v.getX() - w.getX();
	float deltaY = v.getY() - w.getY();
	float deltaZ = v.getZ() - w.getZ();

	return std::sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
}

void Vector::noramlizeThis(Vector& w)
{
	float invSqrtMagnitude = w.inverseSqrtMagnitude();
	w.x *= invSqrtMagnitude;
	w.y *= invSqrtMagnitude;
	w.z *= invSqrtMagnitude;
}

Vector Vector::scale(const Vector& w, const Vector& v)
{
	return Vector(w.getX() * v.getX(), w.getY() * v.getY(), w.getZ() * v.getZ());
}

Vector Vector::operator+(const float& a)
{
	return Vector(this->x + a, this->y + a, this->z + a);
}

Vector Vector::operator-(const float& a)
{
	return Vector(this->x - a, this->y - a, this->z - a);
}

Vector Vector::operator*(const float& a)
{
	return Vector(this->x * a, this->y * a, this->z * a);
}

Vector Vector::operator/(const float& a)
{
	return Vector(this->x / a, this->y / a, this->z / a);
}

Vector Vector::operator+(const Vector& a)
{
	return Vector(this->x + a.getX(), this->y + a.getY(), this->z + a.getZ());
}

Vector Vector::operator-(const Vector& a)
{
	return Vector(this->x - a.getX(), this->y - a.getY(), this->z - a.getZ());
}

Vector Vector::operator*(const Vector& a)
{
	return Vector(this->x * a.getX(), this->y * a.getY(), this->z * a.getZ());
}

Vector Vector::operator/(const Vector& a)
{
	return Vector(this->x / a.getX(), this->y / a.getY(), this->z / a.getZ());
}



