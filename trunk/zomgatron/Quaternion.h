#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#include "d3dx9math.h"
#include "Matrix.h"
#include "Operations3D.h"

class Quaternion{
protected:
public:
	Quaternion():x(0), y(0), z(0), w(0) {}
	Quaternion(const Quaternion& from);
	Quaternion(Vector3 axis, float angle);

	float x, y, z, w;

	Quaternion operator *(const Quaternion& rhs);
	Vector3 operator *(const Vector3& rhs);
	operator Matrix ();

	void Normalize();
	void Invert();

	static Quaternion GetProduct(Quaternion* lhs, Quaternion* rhs);
	static Vector3 GetProduct(Quaternion* lhs, Vector3* rhs);
	static Quaternion Normalized(Quaternion toNormalize);
	static Quaternion Inverted(Quaternion toInvert);
};

#endif
