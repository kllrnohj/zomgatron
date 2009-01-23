#include "Button.h"

Button::Button(void (*clickResponse)(UIBase*), std::string text): text(text), UIBase(NULL, clickResponse){
	//D3DXCreateTexture(DirectXObjects::D3DDEV, 256, 256, D3DX_DEFAULT, /*D3DUSAGE_RENDERTARGET D3DUSAGE_DYNAMIC*/ NULL, D3DFMT_X8R8G8B8, D3DPOOL_MANAGED, &this->background);
	//DirectXObjects::D3DDEV->SetRender
	if(buttonImage == NULL){
		buttonImage = EngineStatics::Engine->LoadImageFromFile(IMAGE_FN_BUTTON);
		/*D3DXCreateTextureFromFile(DirectXObjects::D3DDEV, IMAGE_FN_BUTTON, &buttonImage);*/
	}
	background = buttonImage;
	color = BUTTON_DEFAULT_COLOR;
	clickStarted = false;
}

void Button::Draw(float drawDepth){
	EngineStatics::Engine->DrawTexture(this->background, itemRect, drawDepth, color);
	EngineStatics::Engine->DrawString(text, itemRect, COLORARGB(255, 255, 255, 255), (ALIGNMENT)(JHCENTER|JVCENTER));
	/*D3DXMATRIX old;
	DirectXObjects::D3DSPR->GetTransform(&old);
	DirectXObjects::D3DSPR->SetTransform(&mat);
	DirectXObjects::D3DSPR->Draw(this->background, NULL, NULL, &D3DXVECTOR3(itemRect.left, itemRect.top, drawDepth), color);*/
	//DirectXObjects::FONT->DrawTextA(NULL, text.c_str(), -1, &itemRect, DT_CENTER | DT_VCENTER, D3DCOLOR_XRGB(255, 255, 255));
	//DirectXObjects::D3DSPR->SetTransform(&old);
}
void Button::DoInput(unsigned char keystate[256], MouseState* mousestate, Vector2 mousePos){
	// A BUTTON SHOULD NOT HAVE CHILDREN.
	if(mousePos.x >= itemRect.left && mousePos.x <= itemRect.right && mousePos.y >= itemRect.top && mousePos.y <= itemRect.bottom){
		// mouse is on button
		if(!mousestate->left && clickStarted){
			clickStarted = false;
			clickResponse(this);
		}
		if(mousestate->left && !clickStarted){
			clickStarted = true;
		}
		if(clickStarted)
			color = BUTTON_CLICK_COLOR;
		else
			color = BUTTON_HIGHLIGHT_COLOR;
	}else{
		if(!mousestate->left && clickStarted){
			clickStarted = false;
		}
		color = BUTTON_DEFAULT_COLOR;
	}
}

void* Button::buttonImage = NULL;