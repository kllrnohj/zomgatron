#ifndef __BOUNDINGBOX_H__
#define __BOUNDINGBOX_H__

#include "d3dx9math.h"
#include "Engine.h"

class BoundingBox{
protected:
	Vector3 min, max;
public:
	BoundingBox(Vector3 min, Vector3 max){ this->min = min; this->max = max; }

	bool Intersects(BoundingBox* test, Vector3 thisPos, Vector3 testPos);
};

#endif
