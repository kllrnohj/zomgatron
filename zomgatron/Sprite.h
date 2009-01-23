#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "DirectX.h"
#include "d3dx9.h"
#include <vector>

class Sprite{
protected:
	bool draw;
	void* image;

	Quad* sourceRect;

	Vector3 position;

public:
	Sprite(char* file);

	bool GetDraw() { return draw; }
	void SetDraw(bool draw) { this->draw = draw; }

	Quad* GetSourceRect() { return sourceRect; }
	void SetSourceRect(Quad* sr) { sourceRect = sr; }
	void SetSourceRect(int x, int y, int x2, int y2) { if(!sourceRect){sourceRect = new Quad();} sourceRect->left = x; sourceRect->top = y; sourceRect->right = x2; sourceRect->bottom = y2; }

	Vector3 GetPosition() { return position; }
	void SetPosition(Vector3 position) { this->position = position; }
	void MoveUp(float val) { this->position.y -= val; }
	void MoveRight(float val) { this->position.x += val; }

	void* GetImage() { return image; }
};

#endif
