#include "OpenGL.h"
#include <windows.h>
#include "INFOSANDTHINGIES.h"

HWND window;
float aspectRatio;
const char clzname[] = "omgwtfitsaclassname";
LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra						= 0;
	wc.cbSize							= sizeof(WNDCLASSEX);
	wc.cbWndExtra						= 0;
	wc.style							= (CS_HREDRAW | CS_VREDRAW);
	//wc.hbrBackground					= (HBRUSH)COLOR_WINDOW;
	wc.hCursor							= LoadCursor(NULL, IDC_ARROW);
	wc.hIcon							= LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance						= hInstance;
	wc.lpfnWndProc						= WinProc;
	wc.lpszClassName					= clzname;
	
	RegisterClassEx(&wc);

	ShowCursor(false);

	RECT desktop;
	GetWindowRect(GetDesktopWindow(), &desktop);

	int width;
	int height;
	DWORD style;

#if APP_WINDOWED
	width = desktop.right / 2;
	height = desktop.bottom / 2;
	style = WS_OVERLAPPEDWINDOW;
#else
	width = desktop.right;
	height = desktop.bottom;
	style = WS_POPUP | WS_EX_TOPMOST;
#endif

	aspectRatio = (float)width / (float)height;

	window = CreateWindowEx(NULL, clzname, "zomgatron!", style, 0, 0, width, height, NULL, NULL, hInstance, NULL);

	ShowWindow(window, nShowCmd);

	MSG msg;

	/*Engine* engine = */new OpenGL(window, hInstance, width, height);

	DWORD milli = GetTickCount();
	while(true){
		if((float)GetTickCount() - (float)milli >= (1000.0f / 60.0f)){
			if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
				if(msg.message == WM_QUIT)
					break;

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			RECT windowRect;
			GetWindowRect(window, &windowRect);
			if(GetForegroundWindow() == window)
				SetCursorPos(windowRect.left + (width / 2), windowRect.top + (height / 2));
			if(!EngineStatics::Engine->GameLoop(GetTickCount() - milli))
				break;
			milli = GetTickCount();
		}else{
			Sleep(1);
		}
	}

	EngineStatics::Engine->Cleanup();

	return (int)msg.wParam;
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
	switch(msg){
		case WM_CLOSE:
			{
				DestroyWindow(hWnd);
			}break;
		case WM_DESTROY:
			{
				PostQuitMessage(0);
			}break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}