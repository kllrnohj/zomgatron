#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <vector>
#include <string>

#define COLORARGB(a,r,g,b) ((DWORD)((((a)&0xFF)<<24)|(((r)&0xFF)<<16)|(((g)&0xFF)<<8)|((b)&0xFF)))
#define COLORRGB(r,g,b) COLORARGB(255,r,g,b)
#define COLORA(color) ((color&0xFF000000) >> 24)
#define COLORR(color) ((color&0x00FF0000) >> 16)
#define COLORG(color) ((color&0x0000FF00) >> 8)
#define COLORB(color) ((color&0x000000FF))

class Light;
class Thingie;
class DrawnObject;
class VBufObject;
class Sprite;
class Window;
class BoundingBox;
class Character;
struct ZOMGVERTEX;

#ifndef DWORD
typedef unsigned long DWORD;
#endif

struct Vector2{
	float x, y;
	
	Vector2(){x = 0; y = 0;}
	Vector2(const Vector2& copy) { x = copy.x; y = copy.y; }
	Vector2(float x, float y) { this->x = x; this->y = y; }

	Vector2 operator *(const float& rhs) { Vector2 result; result.x = x * rhs; result.y = y * rhs; return result; }
	Vector2 operator *(const Vector2& rhs) { Vector2 result; result.x = x * rhs.x; result.y = y * rhs.y; return result; }
	Vector2 operator +(const Vector2& rhs) { Vector2 result; result.x = x + rhs.x; result.y = y + rhs.y; return result; }
};

struct Vector3{
	float x, y, z;

	Vector3(){x = 0; y = 0; z = 0;}
	Vector3(const Vector3& copy) { x = copy.x; y = copy.y; z = copy.z; }
	Vector3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }

	Vector3 operator *(const float& rhs) { Vector3 result; result.x = x * rhs; result.y = y * rhs; result.z = z * rhs; return result; }
	Vector3 operator /(const float& rhs) { Vector3 result; result.x = x / rhs; result.y = y / rhs; result.z = z / rhs; return result; }
	Vector3 operator *(const Vector3& rhs) { Vector3 result; result.x = x * rhs.x; result.y = y * rhs.y; result.z = z * rhs.z; return result; }
	Vector3 operator +(const Vector3& rhs) { Vector3 result; result.x = x + rhs.x; result.y = y + rhs.y; result.z = z + rhs.z; return result; }
	Vector3 operator -(const Vector3& rhs) { Vector3 result; result.x = x - rhs.x; result.y = y - rhs.y; result.z = z - rhs.z; return result; }
	Vector3 operator /(const Vector3& rhs) { Vector3 result; result.x = x / rhs.x; result.y = y / rhs.y; result.z = z / rhs.z; return result; }
	bool operator == (const Vector3& rhs) { return (x == rhs.x && y == rhs.y && z == rhs.z); }
};

struct Mesh{
	int numVertices;
	Vector3* vertices;
	Vector3* normals;
	Vector2* texCoords;
};

struct Vector4{
	float x,y,z,w;
	Vector4() { x= 0; y =0; z= 0; w = 0;}
	Vector4(const Vector4& copy) { x = copy.x; y = copy.y; z = copy.z; w = copy.w;}
	Vector4(float x, float y, float z, float w) { this->x = x; this->y = y; this->z = z; this->w = w; }
};

struct Point2{
	int a, b;
};

struct Point3{
	int a, b, c;
};

struct Quad{
	int top, left, bottom, right;
};

struct MouseState{
	bool left, right, middle;
	float changeX, changeY, changeZ;
};

enum ALIGNMENT{
	JLEFT = 0x01,
	JRIGHT = 0x02,
	JTOP = 0x04,
	JBOTTOM = 0x08,
	JHCENTER = 0x10,
	JVCENTER = 0x20,
	JPARAGRAPH = 0x40,
};

enum LIGHTTYPE{
	LTSPOT = 0x01,
	LTPOINT = 0x02,
	LTDIRECTIONAL = 0x04,
};

using namespace std;

class Engine{
protected:
public:
	// for now lets not force windows to this level
	//Engine(HWND target, HINSTANCE hInstance, unsigned int width, unsigned int height);
	virtual bool GameLoop(unsigned long elapsedms) = 0;

	virtual Thingie* GetCamera() = 0;

	virtual void AddObject(DrawnObject* object) = 0;
	virtual void AddObject(VBufObject* object) = 0;
	virtual void AddObject(Sprite* object) = 0;

	virtual vector<DrawnObject*>* GetDrawnObjects() = 0;
	virtual vector<VBufObject*>* GetVertexObjects() = 0;
	virtual vector<Light*>* GetLightObjects() = 0;

	virtual Character* GetPlayer() = 0;
	virtual void SetPlayer(Character* newPlayer) = 0;

	virtual void SetWorldObjects(std::vector<DrawnObject*> newList) = 0;
	virtual void SetVertexObjects(std::vector<VBufObject*> newList) = 0;
	virtual void SetLightObjects(std::vector<Light*> newList) = 0;

	virtual DrawnObject* GetActivatedObject() = 0;

	virtual void SetOpenWindow(Window* window) = 0;
	virtual Window* GetOpenWindow() = 0;
	virtual unsigned int GetWidth() = 0;
	virtual unsigned int GetHeight() = 0;

	virtual void Cleanup() = 0;

	// this stuff handles type differences between engines by using void pointers
	// the engine needs to know how to cast a void*, where the classes that use
	// them must keep them organized so they never pass a void* that doesn't
	// point to the real object type.
	virtual void* LoadImageFromFile(std::string filename) = 0;
	virtual void* LoadMeshFromFile(std::string filename, void** materials, void** textures, int* numPieces) = 0;

	virtual void DrawTexture(void* texture, Quad position, float drawDepth, DWORD color) = 0;
	virtual void DrawString(std::string text, Quad position, DWORD color, ALIGNMENT alignFlags) = 0;
	virtual BoundingBox* ComputeBoundingBox(void* mesh) = 0;
	virtual void ReleaseMesh(void* mesh) = 0;

	virtual void SetLightEnabled(int index, bool enabled) = 0;
	virtual void CreateLight(unsigned long thisLight, Vector3 position, Vector3 direction, LIGHTTYPE type, DWORD diffuse, DWORD specular, float range, float atten0, float atten1, float atten2) = 0;

	virtual void* CreateVertexBuffer(ZOMGVERTEX* vertices, int count) = 0;
	virtual void ReleaseVertexBuffer(void* vBuf) = 0;
	virtual void* CreateMaterial(DWORD diffuse, DWORD specular, DWORD ambient) = 0;
};

class EngineStatics{
public:
	static Engine* Engine;
};

#endif
