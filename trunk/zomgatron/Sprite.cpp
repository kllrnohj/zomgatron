#include "Sprite.h"

Sprite::Sprite(char* file): draw(true), position(0, 0, 0){
	image = EngineStatics::Engine->LoadImageFromFile(file);
	//D3DXCreateTextureFromFile(DirectXObjects::D3DDEV, file, &image);
	sourceRect = NULL;
}