#ifndef VECTOR_H
#define VECTOR_H

#ifdef MYMATHLIB_EXPORT
#define MYMATHLIB_API __declspec(dllexport)
#else
#define MYMATHLIB_API __declspec(dllimport)
#endif


class MYMATHLIB_API Vector{
public:
	Vector();
	Vector(float x, float y, float z);
	~Vector();

	void operator=(const Vector& other);
	Vector operator+(const Vector& other);
	Vector operator-(const Vector& other);
	Vector operator*(const Vector& other);
	Vector operator/(const Vector& other);

	float x;
	float y;
	float z;
private:

};


#endif