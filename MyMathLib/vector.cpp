#include "vector.h"

Vector::Vector():
	x(0.0f),y(0.0f),z(0.0f){}

Vector::Vector(float x, float y, float z):
	x(x),y(y),z(z){}

Vector::~Vector(){}

void Vector::operator=(const Vector& other){
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

Vector Vector::operator+(const Vector& other){
	return Vector(	this->x + other.x,
					this->y + other.y,
					this->z + other.z);
}
Vector Vector::operator-(const Vector& other){
	return Vector(	this->x - other.x,
					this->y - other.y,
					this->z - other.z);
}
Vector Vector::operator*(const Vector& other){
	return Vector(	this->x * other.x,
					this->y * other.y,
					this->z * other.z);
}
Vector Vector::operator/(const Vector& other){
	return Vector(	this->x / other.x,
					this->y / other.y,
					this->z / other.z);
}