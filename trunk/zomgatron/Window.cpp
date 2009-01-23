#include "Window.h"

Window::Window(): UIBase(NULL, NULL){
	open = true;
	deleteOnClose = false;
	if(windowImage == NULL){
		windowImage = EngineStatics::Engine->LoadImageFromFile(IMAGE_FN_WINDOW);
	}
	background = windowImage;
}

void Window::DoInput(unsigned char keystate[256], MouseState* mousestate, Vector2 mousePos){
	if(mousePos.x >= itemRect.left && mousePos.x <= itemRect.right && mousePos.y >= itemRect.top && mousePos.y <= itemRect.bottom){
		// if it's on the window
		// check if it hit a child
		for(unsigned int x = 0; x < children.size(); x++){
			children.at(x)->DoInput(keystate, mousestate, mousePos); // pass input to children
		}
	}
}
void Window::Draw(float drawDepth){
	EngineStatics::Engine->DrawTexture(background, itemRect, drawDepth, COLORARGB(200,255,255,255));
	//DirectXObjects::D3DSPR->Draw(background, NULL, NULL, &D3DXVECTOR3((float)itemRect.left, (float)itemRect.top, drawDepth), D3DCOLOR_ARGB(200, 255, 255, 255));
	for(unsigned int x = 0; x < children.size(); x++){
		children.at(x)->Draw(drawDepth / 2.0f);
	}
}

Window::~Window(){
	for(unsigned int x = 0; x < children.size(); x++){
		delete children.at(x);
	}
}

void* Window::windowImage = NULL;