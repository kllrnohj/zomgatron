#ifndef __MYOPENGL_H__
#define __MYOPENGL_H__

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Engine.h"
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

class OpenGL: public Engine{
protected:
	void InitGL();
	HWND target;
	HDC dc;
	HGLRC rc;
	unsigned int width, height;

	void Render();
	bool Update(unsigned long elapsedms);
public:
	OpenGL(HWND target, HINSTANCE hInstance, unsigned int width, unsigned int height);
	virtual bool GameLoop(unsigned long elapsedms);

	virtual Thingie* GetCamera();

	virtual void AddObject(DrawnObject* object);
	virtual void AddObject(VBufObject* object);
	virtual void AddObject(Sprite* object);

	virtual vector<DrawnObject*>* GetDrawnObjects();
	virtual vector<VBufObject*>* GetVertexObjects();
	virtual vector<Light*>* GetLightObjects();

	virtual Character* GetPlayer();
	virtual void SetPlayer(Character* newPlayer);

	virtual void SetWorldObjects(std::vector<DrawnObject*> newList);
	virtual void SetVertexObjects(std::vector<VBufObject*> newList);
	virtual void SetLightObjects(std::vector<Light*> newList);

	virtual DrawnObject* GetActivatedObject();

	virtual void SetOpenWindow(Window* window);
	virtual Window* GetOpenWindow();
	virtual unsigned int GetWidth();
	virtual unsigned int GetHeight();

	virtual void Cleanup();

	// this stuff handles type differences between engines by using void pointers
	// the engine needs to know how to cast a void*, where the classes that use
	// them must keep them organized so they never pass a void* that doesn't
	// point to the real object type.
	virtual void* LoadImageFromFile(std::string filename);
	virtual void* LoadMeshFromFile(std::string filename, void** materials, void** textures, int* numPieces);

	virtual void DrawTexture(void* texture, Quad position, float drawDepth, DWORD color);
	virtual void DrawString(std::string text, Quad position, DWORD color, ALIGNMENT alignFlags);
	virtual BoundingBox* ComputeBoundingBox(void* mesh);
	virtual void ReleaseMesh(void* mesh);

	virtual void SetLightEnabled(int index, bool enabled);
	virtual void CreateLight(unsigned long thisLight, Vector3 position, Vector3 direction, LIGHTTYPE type, DWORD diffuse, DWORD specular, float range, float atten0, float atten1, float atten2);

	virtual void* CreateVertexBuffer(ZOMGVERTEX* vertices, int count);
	virtual void ReleaseVertexBuffer(void* vBuf);
	virtual void* CreateMaterial(DWORD diffuse, DWORD specular, DWORD ambient);

	~OpenGL();
};

#endif
