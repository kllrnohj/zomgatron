#ifndef __OPERATIONS3D_H__
#define __OPERATIONS3D_H__

#include "d3dx9math.h"
#include "Engine.h"
#include <math.h>

class Operations3D{
public:
	static float DotProduct(Vector3 one, Vector3 two);
	static Vector3 CrossProduct(Vector3 one, Vector3 two);
	static float Magnitude(Vector3 one);
	static Vector3 Normifyilation(Vector3 one, float scale = 1.0f);
	static float Distance3D(Vector3 one, Vector3 two);
};

#endif
