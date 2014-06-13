#include "vector2.h"

Vector2::Vector2():
	x(0.0f), y(0.0f){}

Vector2::Vector2(int x, int y):
	x((float)x), y((float)y){}

Vector2::Vector2(float x, float y):
	x(x), y(y){}

Vector2::~Vector2(){}

void Vector2::operator=(const Vector2& other){
	this->x = other.x;
	this->y = other.y;
}
Vector2 Vector2::operator+(const Vector2& other){
	return Vector2(
		this->x + other.x,
		this->y + other.y
	);
}
Vector2 Vector2::operator-(const Vector2& other){
	return Vector2(
		this->x - other.x,
		this->y - other.y
	);
}
Vector2 Vector2::operator*(const Vector2& other){
	return Vector2(
		this->x * other.x,
		this->y * other.y
	);
}
Vector2 Vector2::operator/(const Vector2& other){
	return Vector2(
		this->x / other.x,
		this->y / other.y
	);
}
