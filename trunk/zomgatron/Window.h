#ifndef __WINDOW_H__
#define __WINDOW_H__

#define IMAGE_FN_WINDOW "Data/Images/dialog.png"

#include "d3dx9.h"
#include "UIBase.h"

class Window: public UIBase{
protected:
	static void* windowImage;
	bool open;
	bool deleteOnClose;
public:
	Window();

	void DoInput(unsigned char keystate[256], MouseState* mousestate, Vector2 mousePos) override;
	void Draw(float drawDepth) override;

	void SetOpen(bool val) { open = val; }
	bool GetOpen() { return open; }
	bool GetDeleteOnClose() { return deleteOnClose; }
	void SetDeleteOnClose(bool deleteOnClose) { this->deleteOnClose = deleteOnClose; }

	~Window();
};

#endif
