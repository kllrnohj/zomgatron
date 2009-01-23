#include "OpenGL.h"
#include "DirectX.h"

void OpenGL::InitGL(){
	dc = GetDC(target);
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = (PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER);
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;
	int format = ChoosePixelFormat(dc, &pfd);
	SetPixelFormat(dc, format, &pfd);
	rc = wglCreateContext(dc);
	wglMakeCurrent(dc, rc);


	// set up actual rendering stuffs
	glClearColor(0.0, 0.0, 0.3, 0.0);
	//glColor4f(1.0, 1.0, 1.0, 0.5);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);

	float ambient[4] = { 0.0, 0.0, 0.0, 1.0 };
	float diffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
	float specular[4] = { 1.0, 1.0, 1.0, 1.0 };
	float position[4] = { 0.0, 0.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	float modelAmbient[4] = { 0.1, 0.1, 0.1, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, modelAmbient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	float mSpecular[4] = { 1.0, 1.0, 1.0, 1.0 };
	float mEmission[4] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mSpecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mEmission);
}

OpenGL::OpenGL(HWND target, HINSTANCE hInstance, unsigned int width, unsigned int height): target(target), width(width), height(height){
	EngineStatics::Engine = this;
	InitGL();
}

void OpenGL::Render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW_MATRIX);
	glLoadIdentity();

	// pos, look at, up
	gluLookAt(0.0f, 0.0f, 0.0f, 0.0f, 0.0, 1.0f, 0.0, 1.0, 0.0);

	glNormal3f(0.0, 0.0, -1.0);
		glBegin(GL_TRIANGLES);
		glColor4f(255, 0, 0, 255);
		glVertex3f(-0.3f, 0.3f, 1.0f);
		glColor4f(0, 255, 0, 255);
		glVertex3f(0.3f, 0.3f, 1.0f);
		glColor4f(0, 0, 255, 255);
		glVertex3f(0.0f, -0.3f, 1.0f);
		glEnd();

	SwapBuffers(dc);
}
bool OpenGL::Update(unsigned long elapsedms){
	return true;
}

bool OpenGL::GameLoop(unsigned long elapsedms){
	bool val = Update(elapsedms);
	Render();

	return val;
}

Thingie* OpenGL::GetCamera(){
	return NULL;
}

void OpenGL::AddObject(DrawnObject* object){

}
void OpenGL::AddObject(VBufObject* object){

}
void OpenGL::AddObject(Sprite* object){

}

vector<DrawnObject*>* OpenGL::GetDrawnObjects(){
	return NULL;
}
vector<VBufObject*>* OpenGL::GetVertexObjects(){
	return NULL;
}
vector<Light*>* OpenGL::GetLightObjects(){
	return NULL;
}

Character* OpenGL::GetPlayer(){
	return NULL;
}
void OpenGL::SetPlayer(Character* newPlayer){

}

void OpenGL::SetWorldObjects(std::vector<DrawnObject*> newList){

}
void OpenGL::SetVertexObjects(std::vector<VBufObject*> newList){

}
void OpenGL::SetLightObjects(std::vector<Light*> newList){

}

DrawnObject* OpenGL::GetActivatedObject(){
	return NULL;
}

void OpenGL::SetOpenWindow(Window* window){

}
Window* OpenGL::GetOpenWindow(){
	return NULL;
}
unsigned int OpenGL::GetWidth(){
	return width;
}
unsigned int OpenGL::GetHeight(){
	return height;
}

void OpenGL::Cleanup(){
	if(rc){
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(rc);
	}
	if(target && dc)
		ReleaseDC(target, dc);
}

// this stuff handles type differences between engines by using void pointers
// the engine needs to know how to cast a void*, where the classes that use
// them must keep them organized so they never pass a void* that doesn't
// point to the real object type.
void* OpenGL::LoadImageFromFile(std::string filename){
	return NULL;
}
void* OpenGL::LoadMeshFromFile(std::string filename, void** materials, void** textures, int* numPieces){
	return NULL;
}

void OpenGL::DrawTexture(void* texture, Quad position, float drawDepth, DWORD color){

}
void OpenGL::DrawString(std::string text, Quad position, DWORD color, ALIGNMENT alignFlags){

}
BoundingBox* OpenGL::ComputeBoundingBox(void* mesh){
	return NULL;
}
void OpenGL::ReleaseMesh(void* mesh){

}

void OpenGL::SetLightEnabled(int index, bool enabled){

}
void OpenGL::CreateLight(unsigned long thisLight, Vector3 position, Vector3 direction, LIGHTTYPE type, DWORD diffuse, DWORD specular, float range, float atten0, float atten1, float atten2){

}

void* OpenGL::CreateVertexBuffer(ZOMGVERTEX* vertices, int count){
	return NULL;
}
void OpenGL::ReleaseVertexBuffer(void* vBuf){

}
void* OpenGL::CreateMaterial(DWORD diffuse, DWORD specular, DWORD ambient){
	return NULL;
}

OpenGL::~OpenGL(){
	Cleanup();
}