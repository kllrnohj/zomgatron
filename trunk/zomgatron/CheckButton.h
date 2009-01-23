#ifndef __CHECKBUTTON_H__
#define __CHECKBUTTON_H__

#include "Button.h"

#define IMAGE_FN_CHECKBUTTON "Data/Images/checkbutton.png"
#define CHECKBUTTON_WIDTH 16
#define CHECKBUTTON_HEIGHT 16

class CheckButton: public Button{
protected:
	static void* buttonCheckImage;
public:
	CheckButton(void (*clickResponse)(UIBase*));

	void Draw(float drawDepth) override;
};

#endif
