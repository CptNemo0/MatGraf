#include "Vector.hpp"

// Public methods
Vector::Vector() : x(0.0f), y(0.0f), z(0.0f) {}

Vector::Vector(const float& new_x, const float& new_y, const float& new_z) : x(new_x), y(new_y), z(new_z) {}

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
	float magnitude = getMagnitude();
	this->x = x / ((magnitude));
	this->y = y / ((magnitude));
	this->z = z / ((magnitude));
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

void Vector::zero()
{
	set(0.0f, 0.0f, 0.0f);
}

std::string Vector::toString() const
{
	std::stringstream ss;
	ss << "Vector: (" << x << ", " << y << ", " << z << ")";
	return ss.str();
}

// Static methods
float Vector::dot(const Vector& w, const Vector& v)
{
	return ((w.getX() * v.getX()) + (w.getY() * v.getY()) + (w.getZ() * v.getZ()));
}

float Vector::angle(const Vector& from, const Vector& to)
{
	float dotProduct = Vector::dot(from, to);
	float magnitudeFrom = from.getMagnitude();
	float magnitudeTo = to.getMagnitude();

	if (magnitudeFrom <= 0 || magnitudeTo <= 0)
	{
		return -1;
	}

	return acos(dotProduct / (magnitudeFrom * magnitudeTo));
}

Vector Vector::cross(const Vector& w, const Vector& v)
{
	Vector retValue = Vector();

	retValue.setX(w.getY() * v.getZ() - w.getZ() * v.getY());
	retValue.setY(w.getZ() * v.getX() - w.getX() * v.getZ());
	retValue.setZ(w.getX() * v.getY() - w.getY() * v.getX());
	
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

Vector Vector::lerp(Vector& w, Vector& v, const float& t)
{
	return (w + (v - w) * t);
}

void Vector::zeroThis(Vector& w)
{
	w.set(0.0f, 0.0f, 0.0f);
}

// Operators
// scalar - vector operations
Vector Vector::operator+(const int& a)
{
	return Vector(this->x + a, this->y + a, this->z + a);
}

Vector Vector::operator-(const int& a)
{
	return Vector(this->x - a, this->y - a, this->z - a);
}

Vector Vector::operator*(const int& a)
{
	return Vector(this->x * a, this->y * a, this->z * a);
}

Vector Vector::operator/(const int& a)
{
	return Vector(this->x / a, this->y / a, this->z / a);
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

// component wise operations
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

// dot product
float Vector::operator^(const Vector& a)
{
	return this->x * a.getX() + this->y * a.getY() + this->z * a.getZ();
}
