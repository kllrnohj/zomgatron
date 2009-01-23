#ifndef __DXHEADER_H__
#define __DXHEADER_H__

//#define PLAYER_POS 0
#define TARGETFPS_MS (1000.0f / 60.0f)
#define GROUND_POS 0
#define DISTANCE_BEHIND_PLAYER 12.0f
#define DISTANCE_BEHIND_PLAYER_THEN_SOME 14.5f
#define HEIGHT_ABOVE_PLAYER 4.0f
#define IMAGE_FN_CURSOR "Data/Images/cursor.png"
#define MOUSE_ZDEPTH 0.0f
#define CAMERA_TEXTURE_SIZE_X 256
#define CAMERA_TEXTURE_SIZE_Y 256

class Character;
class Sprite;

#include "Engine.h"
#include "INFOSANDTHINGIES.h"
#include "d3d9.h"
#include "d3dx9.h"
#include "dinput.h"
#include "Thingie.h"
#include "DrawnObject.h"
#include "VBufObject.h"
#include "Window.h"
#include "DialogManager.h"
#include "Light.h"
#include <vector>

using namespace std;

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

class DirectX: public Engine{
protected:
	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 d3ddev;
	LPD3DXFONT font;
	LPDIRECTINPUT8 din;
	LPDIRECTINPUTDEVICE8 keyb;
	LPDIRECTINPUTDEVICE8 mouse;
	LPD3DXSPRITE d3dspr;

	DrawnObject* targetObject;

	Window* openWindow;

	bool didLookAway; // if the camera way turned

	LPD3DXMESH teapot;

	Thingie* camera;
	LPDIRECT3DTEXTURE9 cameraTexture;
	bool renderToTexture;

	unsigned char oldBuffer[256];

	DWORD lastClick;
	LPDIRECT3DTEXTURE9 mouseTexture;
	D3DXVECTOR2 mousePos;
	bool showMouse;
	bool leftDown;
	bool rightDown;

	vector<DrawnObject*> worldObjects;
	vector<VBufObject*> vertexObjects;
	vector<Light*> lightObjects;
	vector<Sprite*> spriteObjects;

	Character* player;

	HWND hWnd;
	HINSTANCE hInstance;

	void InitDevice();
	void InitInput();

	void DoInput(unsigned long elapsedms);
	void DoWindowInput(unsigned long elapsedms);
	void Render();

	bool Update(unsigned long elapsedms);

	unsigned int width, height;
public:
	DirectX(HWND target, HINSTANCE hInstance, unsigned int width, unsigned int height);

	bool GameLoop(unsigned long elapsedms);

	Thingie* GetCamera();

	void Cleanup();

	void AddObject(DrawnObject* object) { worldObjects.push_back(object);}
	void AddObject(VBufObject* object) { vertexObjects.push_back(object); }
	void AddObject(Sprite* object) { spriteObjects.push_back(object); }

	vector<DrawnObject*>* GetDrawnObjects() { return &worldObjects; }
	vector<VBufObject*>* GetVertexObjects() { return &vertexObjects; }
	vector<Light*>* GetLightObjects() { return &lightObjects; }

	Character* GetPlayer() { return player; }
	void SetPlayer(Character* newPlayer) { player = newPlayer; }

	LPD3DXSPRITE GetSprite() { return d3dspr; }
	LPDIRECT3DDEVICE9 GetDevice() { return d3ddev; }
	LPD3DXFONT GetFont() { return font; }

	void SetWorldObjects(std::vector<DrawnObject*> newList) { worldObjects = newList; }
	void SetVertexObjects(std::vector<VBufObject*> newList) { vertexObjects = newList; }
	void SetLightObjects(std::vector<Light*> newList) { lightObjects = newList; }

	DrawnObject* GetActivatedObject();

	void SetOpenWindow(Window* window) { this->openWindow = window; }
	Window* GetOpenWindow() { return this->openWindow; }
	unsigned int GetWidth() { return width; }
	unsigned int GetHeight() { return height; }

	void* LoadImageFromFile(std::string filename);
	void* LoadMeshFromFile(std::string filename, void** materials, void** textures, int* numPieces);

	void DrawTexture(void* texture, Quad position, float drawDepth, DWORD color);
	void DrawString(std::string text, Quad position, DWORD color, ALIGNMENT alignFlags);

	BoundingBox* ComputeBoundingBox(void* mesh);
	void ReleaseMesh(void* mesh) { ((LPD3DXMESH)mesh)->Release(); }
	void SetLightEnabled(int index, bool enabled) { d3ddev->LightEnable(index, enabled); }

	void CreateLight(unsigned long thisLight, Vector3 position, Vector3 direction, LIGHTTYPE type, DWORD diffuse, DWORD specular, float range, float atten0, float atten1, float atten2);

	void* CreateVertexBuffer(ZOMGVERTEX* vertices, int count);
	void ReleaseVertexBuffer(void* vBuf) { ((LPDIRECT3DVERTEXBUFFER9)vBuf)->Release(); }
	void* CreateMaterial(DWORD diffuse, DWORD specular, DWORD ambient);
};

#endif
