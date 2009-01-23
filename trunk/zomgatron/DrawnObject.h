#ifndef __DRAWNOBJECT_H__
#define __DRAWNOBJECT_H__

#include "Thingie.h"
#include "d3dx9.h"
#include "BoundingBox.h"
#include "ThingieStructs.h"
#include <string>

class DrawnObject: public Thingie{
protected:
	void* mesh; // MESH
	void* material; // MATERIAL*
	void* texture; // TEXTURE*
	BoundingBox* bb;

	int numPieces;
public:
	DrawnObject(void* mesh, void* material);
	DrawnObject(void* mesh, void* material, void* texture, int numPieces);

	void* GetMesh() { return mesh; }
	void* GetMaterial() { return material; }
	void* GetTexture() { return texture; }
	BoundingBox* GetBoundingBox() { return bb; }
	~DrawnObject() { delete bb; EngineStatics::Engine->ReleaseMesh(mesh); }

	int getNumPieces() { return numPieces; }
	void setNumPieces(int val) { numPieces = val; }
	virtual bool isCharacter() { return false; }

	virtual void activate() { }
	virtual std::string activationText() { return ""; }
};
#endif
