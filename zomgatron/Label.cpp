#include "Label.h"

Label::Label(int width, int height, std::string text): UIBase(NULL, NULL){
	this->width = width;
	this->height = height;
	this->text = text;
}

void Label::DoInput(unsigned char keystate[256], MouseState* mousestate, Vector2 mousePos){
	// does not have children
	// do nothing
}
void Label::Draw(float drawDepth){
	EngineStatics::Engine->DrawString(text, itemRect, COLORRGB(255,255,255), JPARAGRAPH);
}

Label::~Label(){
}