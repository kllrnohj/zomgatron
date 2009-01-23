#include "Thingie.h"

Thingie::Thingie(){
	position = Vector3(0, 0, 0);
	forward = Vector3(0, 0, 1);
	right = Vector3(1, 0, 0);
	up = Vector3(0, 1, 0);

}

Thingie::Thingie(Vector3 position, Vector3 dirOrLookAt, bool lookAt){
	this->position = position;
	forward = Vector3(0, 0, 1);
	right = Vector3(1, 0, 0);
	up = Vector3(0, 1, 0);
	Vector3 lookV;
	if(lookAt)
		lookV = dirOrLookAt;
	else
		lookV = Vector3(position.x + dirOrLookAt.x, position.y + dirOrLookAt.y, position.z + dirOrLookAt.z);
	this->LookAt(lookV);
}

void Thingie::LookAt(Vector3 position, float percent){
	Vector3 soonLookDir(position.x - this->position.x, position.y - this->position.y, position.z - this->position.z);
	soonLookDir = Operations3D::Normifyilation(soonLookDir);
	Vector3 axisOfRotation = Operations3D::CrossProduct(forward, soonLookDir);

	if(Operations3D::Magnitude(axisOfRotation) == 0.0f)
		return;
	float val = Operations3D::DotProduct(forward, soonLookDir) / (Operations3D::Magnitude(forward) * Operations3D::Magnitude(soonLookDir));
	if(val > 1.0f)
		val = 1.0f;
	if(val < -1.0f)
		val = -1.0f;
	float angle = acos(val);

	Quaternion rotation(axisOfRotation, angle * (percent / 100.0f));

	forward = rotation * forward;
	right = rotation * right;
	up = rotation * up;

	forward = Operations3D::Normifyilation(forward);
	right = Operations3D::Normifyilation(right);
	up = Operations3D::Normifyilation(up);
}

void Thingie::SetPosition(Vector3 position){
	this->position = position;
}

void Thingie::TurnRight(float angle){
	Quaternion rotation(up, angle);

	forward = rotation * forward;
	right = rotation * right;
	up = rotation * up;

	forward = Operations3D::Normifyilation(forward);
	right = Operations3D::Normifyilation(right);
	up = Operations3D::Normifyilation(up);
}
void Thingie::TurnUp(float angle){
	Quaternion rotation(right, angle);

	forward = rotation * forward;
	right = rotation * right;
	up = rotation * up;

	forward = Operations3D::Normifyilation(forward);
	right = Operations3D::Normifyilation(right);
	up = Operations3D::Normifyilation(up);
}
void Thingie::RotateByForward(float angle){
	Quaternion rotation(forward, angle);

	forward = rotation * forward;
	right = rotation * right;
	up = rotation * up;

	forward = Operations3D::Normifyilation(forward);
	right = Operations3D::Normifyilation(right);
	up = Operations3D::Normifyilation(up);
}

void Thingie::RotateAt(Vector3 axis, float angle){
	if(Operations3D::Magnitude(axis) == 0.0f)
		return;
	Quaternion rotation(axis, angle);

	forward = rotation * forward;
	right = rotation * right;
	up = rotation * up;

	forward = Operations3D::Normifyilation(forward);
	right = Operations3D::Normifyilation(right);
	up = Operations3D::Normifyilation(up);
}

void Thingie::MoveRight(float amount){
	Vector3 offset = Operations3D::Normifyilation(right, amount);
	position = position + offset;
}
void Thingie::MoveUp(float amount){
	Vector3 offset = Operations3D::Normifyilation(up, amount);
	position = position + offset;
}
void Thingie::MoveForward(float amount){
	Vector3 offset = Operations3D::Normifyilation(forward, amount);
	position = position + offset;
}

Quaternion Thingie::GetQuaternion(){
	Vector3 zForward(0, 0, 1);
	Vector3 axis = Operations3D::CrossProduct(zForward, this->forward);
	//D3DXVec3Normalize(&axis, &axis);
	float val = Operations3D::DotProduct(zForward, this->forward);
	if(val != 0.0f){
		val /= (Operations3D::Magnitude(zForward) * Operations3D::Magnitude(this->forward));
		if(val > 1.0f)
			val = 1.0f;
		if(val < -1.0f)
			val = -1.0f;
			val = acos(val);
	}

	Quaternion fromForward(axis, val);

	Vector3 fakeUp = fromForward * Vector3(0, 1, 0);
	fakeUp = Operations3D::Normifyilation(fakeUp);
	axis = Operations3D::CrossProduct(fakeUp, this->up);
	float val2 = Operations3D::DotProduct(fakeUp, this->up);
	if(val2 != 0.0f){
		val2 /= (Operations3D::Magnitude(fakeUp) * Operations3D::Magnitude(this->up));
		if(val2 > 1.0f)
			val2 = 1.0f;
		if(val2 < -1.0f)
			val2 = -1.0f;
		val2 = acos(val2);
	}

	Quaternion forwardRot(axis, val2);

	return (forwardRot * fromForward);
}

Matrix Thingie::GetMatrix(){
	return (Matrix)GetQuaternion();
}