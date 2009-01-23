#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "d3d9.h"
#include "d3dx9.h"

#include "Thingie.h"

class Light: public Thingie{
private:
	static unsigned long LIGHT_NUM;
	unsigned long thisLight;
protected:
	LIGHTTYPE type;
	DWORD diffuse,specular;
	float range, atten0, atten1, atten2;
public:
	Light(LIGHTTYPE type, DWORD diffuse, DWORD specular, float range, float atten0, float atten1, float atten2);

	void GenerateStruct();
	void SetEnabled(bool enabled);

	LIGHTTYPE GetType() { return type; }
	DWORD GetDiffuse() { return diffuse; }
	DWORD GetSpecular() { return specular; }
	float GetRange() { return range; }
	float GetAtten0() { return atten0; }
	float GetAtten1() { return atten1; }
	float GetAtten2() { return atten2; }
};

#endif
