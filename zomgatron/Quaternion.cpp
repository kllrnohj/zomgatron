#include "Quaternion.h"
#include <math.h>

Quaternion::Quaternion(const Quaternion& from){
	this->x = from.x;
	this->y = from.y;
	this->z = from.z;
	this->w = from.w;
}
Quaternion::Quaternion(Vector3 axis, float angle){
	float sinAngle;

	angle *= 0.5;
	Vector3 newAxis;
	newAxis = Operations3D::Normifyilation(axis);
	sinAngle = sin(angle);

	this->x = newAxis.x * sinAngle;
	this->y = newAxis.y * sinAngle;
	this->z = newAxis.z * sinAngle;
	this->w = cos(angle);
}

Quaternion Quaternion::operator *(const Quaternion& rhs){
	return Quaternion::GetProduct(this, (Quaternion*)&rhs);
}
Vector3 Quaternion::operator *(const Vector3& rhs){
	return Quaternion::GetProduct(this, (Vector3*)&rhs);
}

Quaternion::operator Matrix (){
	Matrix matrix;
	
	matrix.values[0][0]  = (1.0f - (2.0f * ((this->y * this->y) + (this->z * this->z))));
	matrix.values[0][1]  =         (2.0f * ((this->x * this->y) + (this->z * this->w)));
	matrix.values[0][2]  =         (2.0f * ((this->x * this->z) - (this->y * this->w)));
	matrix.values[0][3]  = 0.0f;
	matrix.values[1][0]  =         (2.0f * ((this->x * this->y) - (this->z * this->w)));
	matrix.values[1][1]  = (1.0f - (2.0f * ((this->x * this->x) + (this->z * this->z))));
	matrix.values[1][2]  =         (2.0f * ((this->y * this->z) + (this->x * this->w)));
	matrix.values[1][3]  = 0.0f;
	matrix.values[2][0]  =         (2.0f * ((this->x * this->z) + (this->y * this->w)));
	matrix.values[2][1]  =         (2.0f * ((this->y * this->z) - (this->x * this->w)));
	matrix.values[2][2] = (1.0f - (2.0f * ((this->x * this->x) + (this->y * this->y))));
	matrix.values[2][3] = 0.0f;
	matrix.values[3][0] = 0.0f;
	matrix.values[3][1] = 0.0f;
	matrix.values[3][2] = 0.0f;
	matrix.values[3][3] = 1.0f;

	return matrix;
}

void Quaternion::Normalize(){
	float magnitude = sqrt(x * x + y * y + z * z + w * w);
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
	w /= magnitude;
}

void Quaternion::Invert(){
	float i = 1.0f / (x * x + y * y + z * z + w * w);
	x *= -i;
	y *= -i;
	z *= -i;
	w *= i;
}

Quaternion Quaternion::GetProduct(Quaternion* lhs, Quaternion* rhs){
	Vector3 vec1, vec2, cross;
	Quaternion result;
	float angle;

	vec1.x = lhs->x;
	vec1.y = lhs->y;
	vec1.z = lhs->z;
	vec2.x = rhs->x;
	vec2.y = rhs->y;
	vec2.z = rhs->z;
	angle = lhs->w * rhs->w - Operations3D::DotProduct(vec1, vec2);
	cross = Operations3D::CrossProduct(vec1, vec2);

	vec1.x *= rhs->w;
	vec1.y *= rhs->w;
	vec1.z *= rhs->w;
	vec2.x *= lhs->w;
	vec2.y *= lhs->w;
	vec2.z *= lhs->w;

	result.x = vec1.x + vec2.x + cross.x;
	result.y = vec1.y + vec2.y + cross.y;
	result.z = vec1.z + vec2.z + cross.z;
	result.w = angle;

	return result;
}

Quaternion Quaternion::Normalized(Quaternion toNormalize){
	toNormalize.Normalize();
	return toNormalize;
}
Quaternion Quaternion::Inverted(Quaternion toInvert){
	toInvert.Invert();
	return toInvert;
}

Vector3 Quaternion::GetProduct(Quaternion* lhs, Vector3* rhs){
	Quaternion vecQuat, invQuat, resQuat;
	Vector3 result;
	
	vecQuat.x = rhs->x;
	vecQuat.y = rhs->y;
	vecQuat.z = rhs->z;
	vecQuat.w = 0.0f;

	invQuat = Quaternion::Inverted(*lhs);
	resQuat = Quaternion::GetProduct(&vecQuat, &invQuat);
	resQuat = Quaternion::GetProduct(lhs, &resQuat);

	result.x = resQuat.x;
	result.y = resQuat.y;
	result.z = resQuat.z;

	return result;
}