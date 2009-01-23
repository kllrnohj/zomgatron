#include "CheckButton.h"

void* CheckButton::buttonCheckImage = NULL;

CheckButton::CheckButton(void (*clickResponse)(UIBase *)): Button(clickResponse, "") {
	if(buttonCheckImage == NULL){
		buttonCheckImage = EngineStatics::Engine->LoadImageFromFile(IMAGE_FN_CHECKBUTTON);
	}
	background = buttonCheckImage;
}

void CheckButton::Draw(float drawDepth){
	EngineStatics::Engine->DrawTexture(this->background, itemRect, drawDepth, color);
}