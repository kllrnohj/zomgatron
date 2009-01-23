#include "DirectX.h"
#include "Sprite.h"
#include "Conversation.h"
#include "Character.h"
#include "Location.h"

D3DXVECTOR3 V3toV3(Vector3 from){
	D3DXVECTOR3 result;
	result.x = from.x;
	result.y = from.y;
	result.z = from.z;
	return result;
}

Vector3 V3toV3(D3DXVECTOR3 from){
	Vector3 result;
	result.x = from.x;
	result.y = from.y;
	result.z = from.z;
	return result;
}

D3DMATRIX MattoMat(Matrix* from){
	D3DMATRIX result;
	for(int x = 0; x < 4; x++){
		for(int y = 0; y < 4; y++){
			result.m[x][y] = from->values[x][y];
		}
	}
	return result;
}
RECT RtoR(Quad from){
	RECT result;
	result.top = from.top;
	result.bottom = from.bottom;
	result.left = from.left;
	result.right = from.right;
	return result;
}

DirectX::DirectX(HWND target, HINSTANCE hInstance, unsigned int width, unsigned int height) {
	didLookAway = false;
	targetObject = NULL;
	leftDown = false;
	rightDown = false;
	openWindow = NULL;
	lastClick = 0;
	showMouse = false;
	renderToTexture = false;
	mousePos.x = (float)(width / 2);
	mousePos.y = (float)(height / 2);
	hWnd = target;
	this->hInstance = hInstance;
	this->width = width;
	this->height = height;
	InitDevice();
	do{
	try{
		InitInput();
		break;
	}catch(...){
		
	}
	}while(true);

	/************** SET UP STATIC VARIABLES *********************************/
	EngineStatics::Engine = this;
	/*************** END INITIALIZATION MATERIAL ****************************/
	/************************************************************************/
	/************************************************************************/
	/************************************************************************/

	/*************** CREATE SOME TEST WORLD OBJECTS *************************/
	player = Character::GetCharacter("player");
	Location::ChangeLocation("Home");
	//AddObject(Character::GetCharacter("player"));
	//AddObject(Character::GetCharacter("test"));
	//AddObject(new VBufObject(500.0f, 500.0f, 100, 100, D3DCOLOR_XRGB(0, 200, 0)));

	//worldObjects.at(PLAYER_POS)->MoveForward(10.0f);
	//worldObjects.at(PLAYER_POS)->MoveRight(5.0f);
	//worldObjects.at(1)->MoveForward(5.0f);
	//worldObjects.at(1)->MoveRight(2.0f);
	//vertexObjects.at(GROUND_POS)->MoveUp(-1.0f);
	//vertexObjects.at(GROUND_POS)->MoveRight(-250.0f);
	//vertexObjects.at(GROUND_POS)->MoveForward(-250.0f);

	D3DXCreateTextureFromFile(d3ddev, IMAGE_FN_CURSOR, &mouseTexture);
	if(FAILED(D3DXCreateTexture(d3ddev, CAMERA_TEXTURE_SIZE_X, CAMERA_TEXTURE_SIZE_Y, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &cameraTexture)))
		throw "Could not create camera texture.";

	/*Light* l = new Light(D3DLIGHT_POINT, Light::MakeColor(0.3f, 0.3f, 0.3f, 1.0f), Light::MakeColor(1.0f, 1.0f, 1.0f, 1.0f), 300.0f, 0.001f, 0.015f, 0.0015f);
	l->SetPosition(D3DXVECTOR3(0.0f, 5.0f, 10.0f));
	l->GenerateStruct();
	l->SetEnabled(true);*/
	/*************** DONE CREATING SOME TEST WORLD OBJECTS ******************/
	
	camera = new Thingie();
	ZeroMemory(oldBuffer, 256);
}

void DirectX::InitDevice(){
	if(!this->hWnd)
		throw "3D Engine does not have valid target window";

		// get interface
	this->d3d = Direct3DCreate9(D3D_SDK_VERSION);

	if(!d3d)
		throw "Could not create Direct3D Interface";
	

	// setup presentation parameters
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.SwapEffect				= D3DSWAPEFFECT_DISCARD;
#if APP_WINDOWED
	d3dpp.Windowed					= TRUE;
#else
	d3dpp.Windowed					= FALSE;
#endif
	d3dpp.EnableAutoDepthStencil	= TRUE;
	if(SUCCEEDED(d3d->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DFMT_X8R8G8B8, FALSE, D3DMULTISAMPLE_4_SAMPLES, NULL)))
		d3dpp.MultiSampleType		= D3DMULTISAMPLE_4_SAMPLES;
	d3dpp.AutoDepthStencilFormat	= D3DFMT_D16;
	d3dpp.hDeviceWindow				= this->hWnd;
	d3dpp.BackBufferFormat			= D3DFMT_A8R8G8B8;

	d3dpp.BackBufferWidth			= this->width;
	d3dpp.BackBufferHeight			= this->height;

	// create D3D device
	this->d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		this->hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp, &(this->d3ddev));

	// make sure it worked
	if(!this->d3ddev)
		throw "Could not create Direct3D Device";

	D3DXCreateSprite(d3ddev, &d3dspr);

	if(!d3dspr)
		throw "Could not create Direct3D Sprites";

	// create general purpose font
	D3DXCreateFont(this->d3ddev, 15, 0, FW_NORMAL, 1,
		FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial",
		&(this->font));


	// setup some render states
	d3ddev->SetRenderState(D3DRS_LIGHTING, TRUE);
	d3ddev->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(0, 0, 16));
	d3ddev->SetRenderState(D3DRS_ZENABLE, TRUE);
	d3ddev->SetRenderState(D3DRS_SPECULARENABLE, TRUE);
	d3ddev->SetRenderState(D3DRS_SPECULARMATERIALSOURCE, D3DMCS_MATERIAL);
	d3ddev->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
}
void DirectX::InitInput(){
	// create dinput interface
	if(FAILED(DirectInput8Create(this->hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&(this->din), NULL))){
		throw "Failure to capture new interface";
	}

	// create mouse device
	if(FAILED(this->din->CreateDevice(GUID_SysMouse, &(this->mouse), NULL))){
		throw "Failure to create new mouse device";
	}
	// set mouse format
	if(FAILED(this->mouse->SetDataFormat(&c_dfDIMouse))){
		throw "Failure to set Data format";
	}
	// create keyboard device
	if(FAILED(this->din->CreateDevice(GUID_SysKeyboard, &(this->keyb), NULL))){
		throw "Failure to create new keyboard device";
	}
	// set keyboard format
	if(FAILED(this->keyb->SetDataFormat(&c_dfDIKeyboard))){
		throw "Failure to set keyboard Data format";
	}
	HRESULT temp;
	// set mouse cooperative level
	if(FAILED(temp = this->mouse->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))){
		if(temp == DIERR_INVALIDPARAM)
			throw "Failure to set cooperative level invalid Param for mouse";
		else if(temp == DIERR_NOTINITIALIZED)
			throw "Failure to set cooperative level not initialized for mouse";
		else if(temp == E_HANDLE)
			throw "Failure to set cooperative level not valid HWND for mouse";
		else
			throw "Failure to set cooperative level";
	}
	// set keyboard cooperative level
	if(FAILED(temp = this->keyb->SetCooperativeLevel(hWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE))){
		if(temp == DIERR_INVALIDPARAM)
			throw "Failure to set keyboard cooperative level invalid Param";
		else if(temp == DIERR_NOTINITIALIZED)
			throw "Failure to set keyboard cooperative level not initialized";
		else if(temp == E_HANDLE)
			throw "Failure to set keyboard cooperative level not valid HWND";
		else
			throw "Failure to set keyboard cooperative level";
	}
	// acquire mouse
	if(FAILED(this->mouse->Acquire())){
		throw "Failure to acquire mouse";
	}
	// acquire keyboard
	if(FAILED(this->keyb->Acquire())){
		throw "Failure to acquire keyboard";
	}
}

bool DirectX::GameLoop(unsigned long elapsedms){
	bool val = Update(elapsedms);
	Render();

	return val;
}

Thingie* DirectX::GetCamera(){
	return camera;
}

void DirectX::DoWindowInput(unsigned long elapsedms){
	static byte keystate[256];
	ZeroMemory(keystate, 256);

	static HRESULT hr1;
	if((hr1 = keyb->GetDeviceState(256, (LPVOID)keystate) == DIERR_INPUTLOST)){ //DIERR_INPUTLOST, DIERR_INVALIDPARAM, DIERR_NOTACQUIRED, DIERR_NOTINITIALIZED, E_PENDING
		keyb->Acquire();
	}else if(hr1 == DIERR_INVALIDPARAM){
		throw "Invalid keyboard Parameter";
	}else if(hr1 == DIERR_NOTACQUIRED){
		//MessageBox(Application::hWndMain, "Not Acquired", "Direct Input Error", MB_ICONERROR);
	}else if(hr1 == DIERR_NOTINITIALIZED){
		throw "Keyboard Not Initialized";
	}else if(hr1 == E_PENDING){
		throw "Keyboard E PENDING";
	}

	static DIMOUSESTATE mouseState;
	if(FAILED(mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&mouseState)))
		mouse->Acquire();

	mousePos.x += mouseState.lX;
	mousePos.y += mouseState.lY;

	MouseState* ms = new MouseState();
	ms->left = mouseState.rgbButtons[0];
	ms->right = mouseState.rgbButtons[1];
	ms->middle = mouseState.rgbButtons[2];
	ms->changeX = mouseState.lX;
	ms->changeY = mouseState.lY;
	ms->changeZ = mouseState.lZ;
	openWindow->DoInput(keystate, ms, Vector2(mousePos.x, mousePos.y));
}

void DirectX::DoInput(unsigned long elapsedms){
	lastClick += elapsedms; // tick away

	Vector3 oldPlayerPos = player->GetPosition();

	static byte keystate[256];
	ZeroMemory(keystate, 256);

	static HRESULT hr1;
	if((hr1 = keyb->GetDeviceState(256, (LPVOID)keystate) == DIERR_INPUTLOST)){ //DIERR_INPUTLOST, DIERR_INVALIDPARAM, DIERR_NOTACQUIRED, DIERR_NOTINITIALIZED, E_PENDING
		keyb->Acquire();
	}else if(hr1 == DIERR_INVALIDPARAM){
		throw "Invalid keyboard Parameter";
	}else if(hr1 == DIERR_NOTACQUIRED){
		keyb->Acquire();
	}else if(hr1 == DIERR_NOTINITIALIZED){
		throw "Keyboard Not Initialized";
	}else if(hr1 == E_PENDING){
		throw "Keyboard E PENDING";
	}

	static DIMOUSESTATE mouseState;
	if(FAILED(mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&mouseState)))
		mouse->Acquire();

	bool moved = false;
	if(mouseState.rgbButtons[1] && !rightDown){
		lastClick = 0;
	}
	if(mouseState.rgbButtons[0] && !leftDown){
		lastClick = 0;
	}

	if(abs(mouseState.lX) > 0 || abs(mouseState.lY) > 0){
		camera->TurnUp(mouseState.lY / 150.0f);
		camera->RotateAt(Vector3(0, 1, 0), mouseState.lX / 150.0f);
		didLookAway = true;
	}else{
		//didLookAway += elapsedms;
	}

	if(keystate[DIK_F1] & 0x80){
		openWindow = DialogManager::MakeMessageWindow("Welcome to ZOMGATRON!!! Controls:\r\nWASD:Move\r\nSpace:Interact\r\nQ or E:Strafe left or right\r\n\r\nHave Fun!!", Vector2((width - DIALOG_WIDTH) / 2, (height - DIALOG_HEIGHT) / 2));
	}
	if(keystate[DIK_ESCAPE] & 0x80){
		SendMessage(this->hWnd, WM_CLOSE, (WPARAM)0, (LPARAM)0);
	}
	
	if(keystate[DIK_W] & 0x80){
		player->MoveForward(0.1f * (elapsedms / TARGETFPS_MS));
		moved=true;
	}
	if(keystate[DIK_S] & 0x80){
		player->MoveForward(-0.1f * (elapsedms / TARGETFPS_MS));
		moved=true;
	}
	if(keystate[DIK_A] & 0x80){
		player->TurnRight(-0.05f * (elapsedms / TARGETFPS_MS));
		moved = true;
	}
	if(keystate[DIK_D] & 0x80){
		player->TurnRight(0.05f * (elapsedms / TARGETFPS_MS));
		moved = true;
	}
	if(keystate[DIK_Q] & 0x80){
		player->MoveRight(-0.1f * (elapsedms / TARGETFPS_MS));
		moved=true;
	}
	if(keystate[DIK_E] & 0x80){
		player->MoveRight(0.1f * (elapsedms / TARGETFPS_MS));
		moved=true;
	}
	if(keystate[DIK_SPACE] & 0x80 && !(oldBuffer[DIK_SPACE] & 0x80)){
		if(targetObject)
			targetObject->activate();
		//Conversation::GetConversation("hello")->Show();
	}

	// check for collision (should be abstracted)
	for(unsigned int x = 0; x < worldObjects.size(); x++){

		if(worldObjects.at(x)->GetBoundingBox()->Intersects(player->GetBoundingBox(), worldObjects.at(x)->GetPosition(), player->GetPosition())){
			player->SetPosition(oldPlayerPos);
			moved = false;
			break;
		}
	}

	if(moved)
		didLookAway = false;

	// set rightDown and leftDown at end
	if(!mouseState.rgbButtons[1])
		rightDown = false;
	else
		rightDown = true;
	if(!mouseState.rgbButtons[0])
		leftDown = false;
	else
		leftDown = true;

	memcpy(oldBuffer, keystate, 256);
}

void showBox(UIBase* lol){
	MessageBox(NULL, "WE WIN LOL", "ZOMG", MB_OK);
}

void DirectX::Render(){
	this->d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 64), 1.0f, 0);
	this->d3ddev->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);


	d3ddev->BeginScene();

	if(targetObject){
		RECT targetText;
		targetText.left = 0;
		targetText.right = width;
		targetText.top = 30;
		targetText.bottom = 70;

		font->DrawTextA(NULL, targetObject->activationText().c_str(), targetObject->activationText().length(), &targetText, DT_CENTER, D3DCOLOR_ARGB(200, 255, 255, 255));
	}

	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.bottom = 500;
	rect.right = 500;

	D3DXMATRIX matView;
	D3DXVECTOR3 cpos, cforward, cup;
	cpos = V3toV3(camera->GetPosition());
	cforward = V3toV3(camera->GetForward());
	cup = V3toV3(camera->GetUp());
	D3DXMatrixLookAtLH(&matView, &cpos, &(cpos + cforward), &cup);
	d3ddev->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIX matProjection;
	float aspect = (float)this->width / (float)this->height;
	D3DXMatrixPerspectiveFovLH(&matProjection, D3DXToRadian(45), aspect, 0.1f, 1000.0f);
	d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);

	D3DXMATRIX matTranslate;
	D3DXMATRIX rotater;

	for(unsigned int x = 0; x < worldObjects.size(); x++){
		D3DXVECTOR3 tempPos = V3toV3(worldObjects.at(x)->GetPosition());
		D3DXMatrixTranslation(&matTranslate, tempPos.x, tempPos.y, tempPos.z);
		rotater = MattoMat(&worldObjects.at(x)->GetMatrix());

		/*if(x == PLAYER_POS){
			sprintf(buffer, "%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f", rotater.m[0][0], rotater.m[1][0], rotater.m[2][0], rotater.m[3][0],
				rotater.m[0][1], rotater.m[1][1], rotater.m[2][1], rotater.m[3][1],
				rotater.m[0][2], rotater.m[1][2], rotater.m[2][2], rotater.m[3][2],
				rotater.m[0][3], rotater.m[1][3], rotater.m[2][3], rotater.m[3][3]);

			this->font->DrawTextA(NULL, buffer, -1, &rect, 0, D3DCOLOR_XRGB(255,255,255));
		}*/

		d3ddev->SetTransform(D3DTS_WORLD, &(rotater * matTranslate));

		for(int i = 0; i < worldObjects.at(x)->getNumPieces(); i++){
			DrawnObject* temp = worldObjects.at(x);
			D3DMATERIAL9* materials = ((D3DMATERIAL9*)worldObjects.at(x)->GetMaterial());
			LPDIRECT3DTEXTURE9* textures = ((LPDIRECT3DTEXTURE9*)worldObjects.at(x)->GetTexture());
			LPD3DXMESH mesh = ((LPD3DXMESH)worldObjects.at(x)->GetMesh());
			d3ddev->SetMaterial(&materials[i]);
			d3ddev->SetTexture(0, textures[i]);
			mesh->DrawSubset(i);
		}
	}
	D3DXVECTOR3 tempPos = V3toV3(player->GetPosition());
	D3DXMatrixTranslation(&matTranslate, tempPos.x, tempPos.y, tempPos.z);
	rotater = MattoMat(&player->GetMatrix());
	d3ddev->SetTransform(D3DTS_WORLD, &(rotater * matTranslate));
	for(int i = 0; i < player->getNumPieces(); i++){
			d3ddev->SetMaterial(&((D3DMATERIAL9*)player->GetMaterial())[i]);
			d3ddev->SetTexture(0, ((LPDIRECT3DTEXTURE9*)player->GetTexture())[i]);
			((LPD3DXMESH)player->GetMesh())->DrawSubset(i);
	}

	d3ddev->SetFVF(ZOMGFVF);
	for(unsigned int x = 0; x < vertexObjects.size(); x++){
		D3DXVECTOR3 tempPos = V3toV3(vertexObjects.at(x)->GetPosition());
		D3DXMatrixTranslation(&matTranslate, tempPos.x, tempPos.y, tempPos.z);
		rotater = MattoMat(&vertexObjects.at(x)->GetMatrix());

		d3ddev->SetTransform(D3DTS_WORLD, &(rotater * matTranslate));

		d3ddev->SetMaterial(((D3DMATERIAL9*)vertexObjects.at(x)->GetMaterial()));

		d3ddev->SetStreamSource(0, (LPDIRECT3DVERTEXBUFFER9)vertexObjects.at(x)->GetVertexBuffer(), 0, sizeof(ZOMGVERTEX));
		d3ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, vertexObjects.at(x)->GetNumPrimitives());
	}

	d3dspr->Begin(D3DXSPRITE_ALPHABLEND);

	for(unsigned int x = 0; x < spriteObjects.size(); x++){
		if(spriteObjects.at(x)->GetDraw())
			d3dspr->Draw((LPDIRECT3DTEXTURE9)spriteObjects.at(x)->GetImage(), &RtoR(*spriteObjects.at(x)->GetSourceRect()), NULL, &V3toV3(spriteObjects.at(x)->GetPosition()), D3DCOLOR_XRGB(255, 255 ,255));
	}

	d3dspr->Draw(cameraTexture, NULL, NULL, &D3DXVECTOR3(0, 0, 0), D3DCOLOR_ARGB(200, 255, 255, 255));

	// draw mouse
	if(showMouse)
		d3dspr->Draw(mouseTexture, NULL, NULL, &D3DXVECTOR3(mousePos.x, mousePos.y, MOUSE_ZDEPTH), D3DCOLOR_XRGB(255, 255, 255));
	// draw UIBase elements
	if(openWindow)
		openWindow->Draw(0.5f);

	d3dspr->End();

	d3ddev->EndScene();

	d3ddev->Present(NULL, NULL, NULL, NULL);
}

void DirectX::Cleanup(){
	if(this->d3dspr)
		this->d3dspr->Release();
	if(this->d3ddev)
		this->d3ddev->Release();
	if(this->d3d)
		this->d3d->Release();
	if(this->mouse)
		this->mouse->Release();
	if(this->keyb)
		this->keyb->Release();
	if(this->din)
		this->din->Release();
}

bool DirectX::Update(unsigned long elapsedms){
	D3DXVECTOR3 playerPos = V3toV3(player->GetPosition());

	targetObject = GetActivatedObject();

	// update camera
	if(!didLookAway){
		/*camera->Mimic(worldObjects.at(PLAYER_POS));
		camera->MoveForward(-5.0f);
		camera->MoveUp(3.0f);*/

		camera->LookAt(V3toV3(playerPos), 25.0f);

		float dist = Operations3D::Distance3D(camera->GetPosition(), player->GetPosition());
		if(dist > DISTANCE_BEHIND_PLAYER){
			float mag = dist > DISTANCE_BEHIND_PLAYER_THEN_SOME ? 0.2f : 0.003f;
			camera->MoveForward(mag);
			float oldY = camera->GetPosition().y;
			camera->MoveUp((playerPos.y + HEIGHT_ABOVE_PLAYER) - oldY);
		}

		// make camera up direction... up
		Vector3 up(0, 1, 0);
		float angle = Operations3D::DotProduct(camera->GetUp(), up);
		angle /= (Operations3D::Magnitude(camera->GetUp()) * Operations3D::Magnitude(up));
		Vector3 axis = Operations3D::CrossProduct(camera->GetUp(), up);
		if(angle > 1.0f)
			angle = 1.0f;
		if(angle < -1.0f)
			angle = -1.0f;
		angle = acos(angle);
		camera->RotateAt(axis, angle / 6.0f); // interpolate to up slowly to prevent ugly shit
	}

	// regardless, move camera closer to behind player, but don't change where it's pointing
	// get target position...
	Vector3 targetPos = V3toV3(playerPos) - (player->GetForward() * DISTANCE_BEHIND_PLAYER);
	targetPos.y += HEIGHT_ABOVE_PLAYER;
	Vector3 camTargetDir = targetPos - camera->GetPosition();
	Vector3 camTargetPos = camera->GetPosition() + (camTargetDir / 6.0f);
	camera->SetPosition(camTargetPos);

	// process input last so it can make changes
	if(openWindow == NULL){
		DoInput(elapsedms);
	}else{
		if(openWindow->GetOpen()){
			showMouse = true;
			DoWindowInput(elapsedms);
		}else{
			showMouse = false;
			if(openWindow->GetDeleteOnClose())
				delete openWindow;
			openWindow = NULL;
			DoInput(elapsedms); // call default input handler
		}
	}

	return true;
}

DrawnObject* DirectX::GetActivatedObject(){;
	Vector3 playerPos = player->GetPosition();
	Vector3 wing = player->GetRight();
	wing = Operations3D::Normifyilation(wing);
	Vector3 forward = player->GetForward();
	forward = Operations3D::Normifyilation(forward);
	Vector3 min_(playerPos.x, playerPos.y, playerPos.z);
	Vector3 max_(playerPos.x+(forward.x * 5.0f), playerPos.y+(forward.y * 5.0f), playerPos.z+(forward.z * 5.0f));
	max_ = max_ + (wing * 0.2f);
	BoundingBox b(min_, max_);
	DrawnObject* current = NULL;
	float minDist = 100000.0f;
	for(int x = 0; x < worldObjects.size(); x++){
		if(worldObjects.at(x)->GetBoundingBox()->Intersects(&b, worldObjects.at(x)->GetPosition(), Vector3(0, 0, 0))){
			float dist = Operations3D::Magnitude((playerPos - worldObjects.at(x)->GetPosition()));
			if(dist < minDist || current == NULL){
				current = worldObjects.at(x);
				minDist = dist;
			}
		}
	}

	return current;
}

void* DirectX::LoadImageFromFile(std::string filename){
	LPDIRECT3DTEXTURE9 result;
	D3DXCreateTextureFromFile(this->d3ddev, filename.c_str(), &result);
	return (void*)result;
}
void* DirectX::LoadMeshFromFile(std::string filename, void** materials, void** textures, int* numPieces){
	LPD3DXMESH mesh;
	LPD3DXBUFFER bufMaterial;
	DWORD numMaterials;
	D3DXLoadMeshFromX(filename.c_str(), D3DXMESH_MANAGED, this->d3ddev, NULL, &bufMaterial, NULL, &numMaterials, &mesh);


	///
	D3DMATERIAL9* material;
	LPDIRECT3DTEXTURE9* texture;
	D3DXMATERIAL* tempMaterials = (D3DXMATERIAL*)bufMaterial->GetBufferPointer();
	material = new D3DMATERIAL9[numMaterials];
	texture = new LPDIRECT3DTEXTURE9[numMaterials];
	for(DWORD i = 0; i < numMaterials; i++){
		material[i] = tempMaterials[i].MatD3D;
		material[i].Ambient = material[i].Diffuse;
		string dir = filename;
		dir = dir.substr(0, dir.rfind("/") +1);
		if(tempMaterials[i].pTextureFilename)
			dir += tempMaterials[i].pTextureFilename;
		if(FAILED(D3DXCreateTextureFromFile(this->d3ddev, dir.c_str(), &texture[i])))
			texture[i] = NULL;
	}

	*materials = (void*)material;
	*textures = (void*)texture;
	*numPieces = numMaterials;

	return (void*) mesh;
}

void DirectX::DrawTexture(void* texture, Quad position, float drawDepth, DWORD color){
	this->d3dspr->Draw((LPDIRECT3DTEXTURE9)texture, NULL, NULL, &D3DXVECTOR3(position.left, position.top, drawDepth), color);
}

void DirectX::DrawString(std::string text, Quad position, DWORD color, ALIGNMENT alignFlags){
	DWORD realFlags = 0;
	if(alignFlags & JBOTTOM)
		realFlags |= DT_BOTTOM;
	if(alignFlags & JHCENTER)
		realFlags |= DT_CENTER;
	if(alignFlags & JLEFT)
		realFlags |= DT_LEFT;
	if(alignFlags & JRIGHT)
		realFlags |= DT_RIGHT;
	if(alignFlags & JTOP)
		realFlags |= DT_TOP;
	if(alignFlags & JVCENTER)
		realFlags |= DT_VCENTER;
	if(alignFlags & JPARAGRAPH)
		realFlags |= DT_WORDBREAK;

	RECT rect;
	rect.bottom = position.bottom;
	rect.top = position.top;
	rect.left = position.left;
	rect.right = position.right;

	this->font->DrawTextA(NULL, text.c_str(), -1, &rect, realFlags, color);
}

BoundingBox* DirectX::ComputeBoundingBox(void* vpmesh){
	LPD3DXMESH mesh = (LPD3DXMESH)vpmesh;
	LPDIRECT3DVERTEXBUFFER9 vb;
	mesh->GetVertexBuffer(&vb);
	unsigned long numVertices = mesh->GetNumVertices();
	D3DXVECTOR3* pData;
	mesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pData);
	D3DXVECTOR3 min, max;
	D3DXComputeBoundingBox(pData, numVertices, sizeof(D3DXVECTOR3), &min, &max);
	mesh->UnlockVertexBuffer();
	
	return new BoundingBox(V3toV3(min), V3toV3(max));
}

void DirectX::CreateLight(unsigned long thisLight, Vector3 position, Vector3 direction, LIGHTTYPE type, DWORD diffuse, DWORD specular, float range, float atten0, float atten1, float atten2){
	D3DLIGHT9 result;
	ZeroMemory(&result, sizeof(result));
	result.Attenuation0 = atten0;
	result.Attenuation1 = atten1;
	result.Attenuation2 = atten2;
	result.Diffuse.a = COLORA(diffuse) / 255.0f;
	result.Diffuse.r = COLORR(diffuse) / 255.0f;
	result.Diffuse.g = COLORG(diffuse) / 255.0f;
	result.Diffuse.b = COLORB(diffuse) / 255.0f;
	result.Specular.a = COLORA(specular) / 255.0f;
	result.Specular.r = COLORR(specular) / 255.0f;
	result.Specular.g = COLORG(specular) / 255.0f;
	result.Specular.b = COLORB(specular) / 255.0f;
	result.Position = V3toV3(position);
	result.Direction = V3toV3(direction);
	result.Range = range;
	D3DLIGHTTYPE rtype = (D3DLIGHTTYPE)0;
	if(type & LTPOINT)
		rtype = D3DLIGHT_POINT;
	if(type & LTDIRECTIONAL)
		rtype = D3DLIGHT_DIRECTIONAL;
	if(type & LTSPOT)
		rtype = D3DLIGHT_SPOT;
	result.Type = rtype;

	d3ddev->SetLight(thisLight, &result);
}

void* DirectX::CreateVertexBuffer(ZOMGVERTEX* vertices, int count){
	LPDIRECT3DVERTEXBUFFER9 vBuf;
	void* pVoid;
	d3ddev->CreateVertexBuffer(count * sizeof(ZOMGVERTEX), NULL, ZOMGFVF, D3DPOOL_MANAGED, &vBuf, NULL);
	vBuf->Lock(0, 0, &pVoid, 0);
	memcpy(pVoid, vertices, sizeof(ZOMGVERTEX) * count);
	vBuf->Unlock();

	return vBuf;
}
void* DirectX::CreateMaterial(DWORD diffuse, DWORD specular, DWORD ambient){
	// the material the light interacts
    D3DMATERIAL9* m = new D3DMATERIAL9(); 

	// zero memory, so we can be happy
    ZeroMemory(m, sizeof(D3DMATERIAL9)); 

	// set m's reflective color aspects to default 1.0f

	m->Diffuse.r = COLORR(diffuse) / 255.0f;
		m->Ambient.r/* = m.Specular.r*/ = COLORR(ambient) / 255.0f;
    m->Diffuse.g = COLORG(diffuse) / 255.0f;
		m->Ambient.g/* = m.Specular.g*/ = COLORG(ambient) / 255.0f;
    m->Diffuse.b = COLORB(diffuse) / 255.0f;
		m->Ambient.b/* = m.Specular.b*/ = COLORB(ambient) / 255.0f;
    m->Diffuse.a = COLORA(diffuse) / 255.0f;
		m->Ambient.a/* = m.Specular.a*/ = COLORA(ambient) / 255.0f;

	m->Specular.r/* = m.Emissive.r*/ = COLORR(specular) / 255.0f;
	m->Specular.g/* = m.Emissive.g*/ = COLORG(specular) / 255.0f;
	m->Specular.b/* = m.Emissive.b*/ = COLORB(specular) / 255.0f;
	m->Specular.a/* = m.Emissive.a*/ = COLORA(specular) / 255.0f;

	m->Power = 20;

	return m;
}