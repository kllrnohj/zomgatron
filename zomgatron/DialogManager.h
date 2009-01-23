#ifndef __DIALOGMANAGER_H__
#define __DIALOGMANAGER_H__

#define DIALOG_WIDTH 512
#define DIALOG_HEIGHT 512
#define DIALOG_FIRSTX 16
#define DIALOG_FIRSTY 32
#define DIALOG_MAXX 496
#define DIALOG_MAXY 480

#include "Button.h"
#include "Window.h"
#include "Label.h"

class DialogManager{
public:
	static Window* MakeMessageWindow(std::string text, Vector2 position);

	static void closeWindow(UIBase* caller);
};

#endif
