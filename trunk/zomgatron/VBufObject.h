#ifndef __VBUFOBJECT_H__
#define __VBUFOBJECT_H__

#include "d3dx9.h"
#include "Thingie.h"
#include "ThingieStructs.h"

class VBufObject: public Thingie{
protected:
	void* vBuf;
	void* material; // Material* (still only one, just needs to be 4 bytes)

	unsigned int rows, columns;
	float width, depth;
	DWORD color;

	ZOMGVERTEX* vertices;
	int numVertices;
public:
	VBufObject(float planeWidth, float planeDepth, unsigned int rows, unsigned int columns, DWORD color);

	void* GetVertexBuffer() { return vBuf; }

	unsigned int GetRows() { return rows; }
	unsigned int GetColumns() { return columns; }
	float GetWidth() { return width; }
	float GetDepth() { return depth; }
	DWORD GetColor() { return color; }

	int GetNumVertices() { return numVertices; }
	int GetNumPrimitives() { return (numVertices / 3); }
	void* GetMaterial() { return material; }
	~VBufObject() { delete [] vertices; EngineStatics::Engine->ReleaseVertexBuffer(vBuf); }
};

#endif
