#ifndef __BUTTON_H__
#define __BUTTON_H__

#define IMAGE_FN_BUTTON "Data/Images/button.png"
#define BUTTON_WIDTH 128
#define BUTTON_HEIGHT 32

#define BUTTON_DEFAULT_COLOR D3DCOLOR_XRGB(155, 155, 155)
#define BUTTON_HIGHLIGHT_COLOR D3DCOLOR_XRGB(255, 255, 255)
#define BUTTON_CLICK_COLOR D3DCOLOR_XRGB(100, 100, 100)

#include "UIBase.h"
#include <string>

class Button: public UIBase{
protected:
	static void* buttonImage;
	std::string text;

	DWORD color;
	bool clickStarted;
public:
	Button(void (*clickResponse)(UIBase*), std::string text);

	void Draw(float drawDepth) override;
	void DoInput(unsigned char keystate[256], MouseState* mousestate, Vector2 mousePos) override;
};

#endif
