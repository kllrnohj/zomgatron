#include "VBufObject.h"

VBufObject::VBufObject(float planeWidth, float planeDepth, unsigned int rows, unsigned int columns, DWORD color): color(color), rows(rows), columns(columns), width(planeWidth), depth(planeDepth){
	int count = 6 * rows * columns; // 3 per triangle, 2 triangles per square, etc
	this->vertices = new ZOMGVERTEX[count];
	this->numVertices = count;

	for(int x = 0; x < columns; x++){
		for(int z = 0; z < rows; z++){
			float nearx = x * (planeWidth / (float)columns);
			float farx = (x+1) * (planeWidth / (float)columns);
			float nearz = z * (planeDepth / (float)rows);
			float farz = (z+1) * (planeDepth / (float)rows);

			int pos = (((z * columns) + x) * 6);

			vertices[pos].diffuse = color;
			vertices[pos].nx = 0;
			vertices[pos].ny = 1;
			vertices[pos].nz = 0;
			vertices[pos].x = nearx;
			vertices[pos].y = 0.0f;
			vertices[pos].z = farz;
			vertices[pos].specular = COLORARGB(0, 0, 0, 0);

			vertices[pos+1].diffuse = color;
			vertices[pos+1].nx = 0;
			vertices[pos+1].ny = 1;
			vertices[pos+1].nz = 0;
			vertices[pos+1].x = farx;
			vertices[pos+1].y = 0.0f;
			vertices[pos+1].z = farz;
			vertices[pos+1].specular = COLORARGB(0, 0, 0, 0);

			vertices[pos+2].diffuse = color;
			vertices[pos+2].nx = 0;
			vertices[pos+2].ny = 1;
			vertices[pos+2].nz = 0;
			vertices[pos+2].x = farx;
			vertices[pos+2].y = 0.0f;
			vertices[pos+2].z = nearz;
			vertices[pos+2].specular = COLORARGB(0, 0, 0, 0);

			vertices[pos+3].diffuse = color;
			vertices[pos+3].nx = 0;
			vertices[pos+3].ny = 1;
			vertices[pos+3].nz = 0;
			vertices[pos+3].x = nearx;
			vertices[pos+3].y = 0.0f;
			vertices[pos+3].z = farz;
			vertices[pos+3].specular = COLORARGB(0, 0, 0, 0);

			vertices[pos+4].diffuse = color;
			vertices[pos+4].nx = 0;
			vertices[pos+4].ny = 1;
			vertices[pos+4].nz = 0;
			vertices[pos+4].x = farx;
			vertices[pos+4].y = 0.0f;
			vertices[pos+4].z = nearz;
			vertices[pos+4].specular = COLORARGB(0, 0, 0, 0);

			vertices[pos+5].diffuse = color;
			vertices[pos+5].nx = 0;
			vertices[pos+5].ny = 1;
			vertices[pos+5].nz = 0;
			vertices[pos+5].x = nearx;
			vertices[pos+5].y = 0.0f;
			vertices[pos+5].z = nearz;
			vertices[pos+5].specular = COLORARGB(0, 0, 0, 0);
		}
	}

	vBuf = EngineStatics::Engine->CreateVertexBuffer(vertices, count);
	material = EngineStatics::Engine->CreateMaterial(COLORARGB(255,255,255,255), COLORARGB(0,0,0,0), COLORARGB(255,255,255,255));
}