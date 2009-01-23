#ifndef __THINGIE_H__
#define __THINGIE_H__

#include "Operations3D.h"
#include "d3dx9math.h"
#include "Quaternion.h"

class Thingie{
protected:
	Vector3 position;
	Vector3 forward, right, up;
public:
	Thingie();
	Thingie(Vector3 position, Vector3 dirOrLookAt, bool lookAt = true);

	void LookAt(Vector3 position, float percent = 100.0f);
	void SetPosition(Vector3 position);

	void TurnRight(float angle);
	void TurnUp(float angle);
	void RotateByForward(float angle);

	void RotateAt(Vector3 axis, float angle);

	void MoveRight(float amount);
	void MoveUp(float amount);
	void MoveForward(float amount);

	void Mimic(Thingie* toMimic) { this->position = toMimic->position; this->forward = toMimic->forward; this->right = toMimic->right; this->up = toMimic->up; }

	Vector3 GetPosition() { return position;}
	Vector3 GetForward() { return forward; }
	Vector3 GetRight() { return right; }
	Vector3 GetUp() { return up; }

	Quaternion GetQuaternion();
	Matrix GetMatrix();
};

#endif
