#ifndef VECTOR_2_H
#define VECTOR_2_H

#ifdef MYMATHLIB_EXPORT
	#define MYMATHLIB_API __declspec(dllexport)
#else
	#define MYMATHLIB_API __declspec(dllimport)
#endif


class MYMATHLIB_API Vector2{
public:
	Vector2();
	Vector2(int x, int y);
	Vector2(float x, float y);
	~Vector2();

	void operator=(const Vector2& other);
	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	Vector2 operator/(const Vector2& other);

	float x;
	float y;

private:


};

#endif