#ifndef __LABEL_H__
#define __LABEL_H__

#include "d3dx9.h"
#include "UIBase.h"
#include <string>

class Label: public UIBase{
protected:

	int width, height;
	std::string text;
public:
	Label(int width, int height, std::string text);

	void DoInput(unsigned char keystate[256], MouseState* mousestate, Vector2 mousePos) override;
	void Draw(float drawDepth) override;

	~Label();
};

#endif
