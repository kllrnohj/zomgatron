#include "DialogManager.h"

Window* DialogManager::MakeMessageWindow(std::string str, Vector2 position){
	Window* mainWindow = new Window();
	Quad val;
	val.left = (long)position.x;
	val.top = (long)position.y;
	val.right = val.left + DIALOG_WIDTH;
	val.bottom = val.top + DIALOG_HEIGHT;
	mainWindow->SetRect(val);
	Label* text = new Label(DIALOG_MAXX - DIALOG_FIRSTX, DIALOG_MAXY - DIALOG_FIRSTY - 64, str);
	Quad label;
	label.left = DIALOG_FIRSTX + val.left;
	label.top = DIALOG_FIRSTY + val.top;
	label.right = label.left + (DIALOG_MAXX - DIALOG_FIRSTX);
	label.bottom = label.top + (DIALOG_MAXY - DIALOG_FIRSTY - 64);
	text->SetRect(label);
	mainWindow->GetChildren()->push_back(text);
	Button* accept = new Button(DialogManager::closeWindow, "OK");
	Quad button;
	button.top = label.bottom + 16;
	button.left = label.left + (((DIALOG_MAXX - DIALOG_FIRSTX) - BUTTON_WIDTH) / 2);
	button.bottom = button.top + BUTTON_HEIGHT;
	button.right = button.left + BUTTON_WIDTH;
	accept->SetRect(button);
	accept->SetInfo(mainWindow);
	mainWindow->GetChildren()->push_back(accept);

	mainWindow->SetDeleteOnClose(true);

	return mainWindow;
}

void DialogManager::closeWindow(UIBase* caller){
	// should be called by a button with info of its parent window
	Window* mainWindow = (Window*)caller->GetInfo();
	mainWindow->SetOpen(false);
}