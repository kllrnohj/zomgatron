#ifndef __UIBASE_H__
#define __UIBASE_H__

#include "Engine.h"
#include "d3dx9.h"
#include "dinput.h"
#include <vector>

class UIBase{
protected:
	void* background;
	Quad itemRect;
	std::vector<UIBase*> children;

	bool clickable;
	void (*clickResponse)(UIBase*);

	void* info;

	UIBase(void* background, void (*clickResponse)(UIBase*)): background(background), clickResponse(clickResponse){}
public:
	virtual void DoInput(unsigned char keystate[256], MouseState* mousestate, Vector2 mousePos) = 0;
	virtual void Draw(float drawDepth) = 0;

	void AddChild(UIBase* child) { children.push_back(child); }

	void DoClick() { clickResponse(this); }

	void* GetInfo() { return info; }
	void SetInfo(void* info) { this->info = info; }

	Quad GetRect() { return itemRect; }
	void SetRect(Quad val) { itemRect = val; }

	std::vector<UIBase*>* GetChildren() { return &children; }
};

#endif
