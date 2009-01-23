#include "DrawnObject.h"

DrawnObject::DrawnObject(void* mesh, void* material): mesh(mesh), material(material), Thingie() {
	this->numPieces = 1;
	texture = NULL;
	this->bb = EngineStatics::Engine->ComputeBoundingBox(mesh);
}

DrawnObject::DrawnObject(void* mesh, void* material, void* texture, int numPieces): mesh(mesh), material(material), texture(texture), numPieces(numPieces), Thingie() {
	this->bb = EngineStatics::Engine->ComputeBoundingBox(mesh);
}