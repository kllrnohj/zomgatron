#include "Light.h"

unsigned long Light::LIGHT_NUM = 0;

Light::Light(LIGHTTYPE type, DWORD diffuse, DWORD specular, float range, float atten0, float atten1, float atten2)
: type(type), diffuse(diffuse), specular(specular), range(range), atten0(atten0), atten1(atten1), atten2(atten2){
	thisLight = LIGHT_NUM++;
}

void Light::GenerateStruct(){
	EngineStatics::Engine->CreateLight(thisLight, this->position, this->forward, type, diffuse, specular, range, atten0, atten1, atten2);
}
void Light::SetEnabled(bool enabled){
	EngineStatics::Engine->SetLightEnabled(thisLight, enabled);
}