#include "BoundingBox.h"

bool BoundingBox::Intersects(BoundingBox* test, Vector3 thisPos, Vector3 testPos){
	bool xIntersect = (((((this->min.x + thisPos.x) - (test->min.x + testPos.x)) * (((this->max.x + thisPos.x)) - (test->min.x + testPos.x)) <= 0) || ((((this->min.x + thisPos.x) - ((test->max.x + testPos.x))) * (((this->max.x + thisPos.x)) - ((test->max.x + testPos.x)))) <= 0)) ||
        ((((test->min.x + testPos.x) - (this->min.x + thisPos.x)) * (((test->max.x + testPos.x)) - (this->min.x + thisPos.x)) <= 0) || ((((test->min.x + testPos.x) - ((this->max.x + thisPos.x))) * (((test->max.x + testPos.x)) - ((this->max.x + thisPos.x)))) <= 0)));
    bool yIntersect = (((((this->min.y + thisPos.y) - (test->min.y + testPos.y)) * (((this->max.y + thisPos.y)) - (test->min.y + testPos.y)) <= 0) || ((((this->min.y + thisPos.y) - ((test->max.y + testPos.y))) * (((this->max.y + thisPos.y)) - ((test->max.y + testPos.y)))) <= 0)) ||
        ((((test->min.y + testPos.y) - (this->min.y + thisPos.y)) * (((test->max.y + testPos.y)) - (this->min.y + thisPos.y)) <= 0) || ((((test->min.y + testPos.y) - ((this->max.y + thisPos.y))) * (((test->max.y + testPos.y)) - ((this->max.y + thisPos.y)))) <= 0)));
    bool zIntersect = (((((this->min.z + thisPos.z) - (test->min.z + testPos.z)) * (((this->max.z + thisPos.z)) - (test->min.z + testPos.z)) <= 0) || ((((this->min.z + thisPos.z) - ((test->max.z + testPos.z))) * (((this->max.z + thisPos.z)) - ((test->max.z + testPos.z)))) <= 0)) ||
        ((((test->min.z + testPos.z) - (this->min.z + thisPos.z)) * (((test->max.z + testPos.z)) - (this->min.z + thisPos.z)) <= 0) || ((((test->min.z + testPos.z) - ((this->max.z + thisPos.z))) * (((test->max.z + testPos.z)) - ((this->max.z + thisPos.z)))) <= 0)));

    return xIntersect && yIntersect && zIntersect;
}