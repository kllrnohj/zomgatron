#include "Operations3D.h"

float Operations3D::DotProduct(Vector3 one, Vector3 two){
	return one.x * two.x + one.y * two.y + one.z * two.z;
}

Vector3 Operations3D::CrossProduct(Vector3 one, Vector3 two){
	if(one == two)
		return Vector3(one.x, one.z, -one.y);
	Vector3 result;
	result.x = one.y * two.z - two.y * one.z;
	result.y = 0.0f - (one.x * two.z - two.x * one.z);
	result.z = one.x * two.y - two.x * one.y;

	return result;
}

float Operations3D::Magnitude(Vector3 one){
	return sqrt(one.x * one.x + one.y * one.y + one.z * one.z);
}

Vector3 Operations3D::Normifyilation(Vector3 one, float scale){
	float mag = Operations3D::Magnitude(one);
	one.x /= mag;
	one.y /= mag;
	one.z /= mag;

	one.x *= scale;
	one.y *= scale;
	one.z *= scale;

	return one;
}

float Operations3D::Distance3D(Vector3 one, Vector3 two){
	Vector3 result = two - one;
	return Magnitude(result);
}