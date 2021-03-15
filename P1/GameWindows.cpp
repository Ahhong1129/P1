#include "GameWindows.h"
#include <stdio.h>
#include "resource.h"

//	Window Procedure, for event handling

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	/*GameWindows* gamewindows = gamewindows->getInstance();*/
	switch (message)
	{
		//	The message is post when we destroy the window.
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	
	case WM_KEYDOWN:
		if (wParam == 27) {
			PostQuitMessage(0);
		}
		GameWindows::keyPressed = wParam;
		printf("%d - %d\n", wParam, lParam);
		break;

	case WM_KEYUP:
		GameWindows::keyPressed = 0;

		
		break;

	//case WM_MOUSEMOVE:
	//	GameWindows::mouseX = LOWORD(lParam);
	//	GameWindows::mouseY = HIWORD(lParam);
	//	printf("%d - %d\n", wParam, lParam);
	//	break;

	case WM_LBUTTONDOWN:
		printf("%d - %d\n", wParam, lParam);
		break;

		//	Default handling for other messages.
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

GameWindows::~GameWindows()
{

}


GameWindows* GameWindows::sInstance = NULL;

GameWindows* GameWindows::getInstance()
{
	if (sInstance == NULL) {
		sInstance = new GameWindows;
	}
	return sInstance;
}

void GameWindows::releaseInstance()
{
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

int GameWindows::keyPressed = 0;
int GameWindows::mouseX = 0;
int GameWindows::mouseY = 0;

GameWindows::GameWindows()
{
	this->hInstance = GetModuleHandle(NULL);
	this->g_hWnd = NULL;
	ZeroMemory(&wndClass, sizeof(wndClass));
}


void GameWindows::init(){
	
	//	Window's structure

	//	Sset all members in wndClass to 0.
	

	//	Filling wndClass. You are to refer to MSDN for each of the members details.
	//	These are the fundamental structure members to be specify, in order to create your window.
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACKONWHITE);
	wndClass.hCursor = LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1));
	wndClass.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
	wndClass.hInstance = hInstance;	//	GetModuleHandle(NULL);
	wndClass.lpfnWndProc = WindowProcedure;
	wndClass.lpszClassName = "My Window";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//	Register the window.
	RegisterClass(&wndClass);

	
	//	You are to refer to MSDN for each of the parameters details.
	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "My Window's Name", WS_OVERLAPPEDWINDOW, 0, 100, 400, 900, NULL, NULL, hInstance, NULL);


	ShowWindow(g_hWnd, 1);

	RECT rcClient, rcWind;
	GetClientRect(g_hWnd, &rcClient);
	GetWindowRect(g_hWnd, &rcWind);

	int x = (rcWind.right - rcWind.left) - rcClient.right;
	int y = (rcWind.bottom - rcWind.top) - rcClient.bottom;


	printf("%d,%d\n", x, y);

	//	Some interesting function to try out.
		/*ShowCursor(false);*/
}
//	use int main if you want to have a console to print out message

bool GameWindows::isWindowsRunning() {
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

		/*
			The if- version process one message per one iteration loop
			The while- version will clear the message queue before dealing with your own code.

			Another function is GetMessage.
			This function is not suitable for game, because it will block your program until it recieves a message.
			your code will only executed when you have messages, otherwies your pogram will be waiting... (similar to cin)
			Suitable for event based program, such as bussiness app.
		*/
		//	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			//	Receive a quit message
			if (msg.message == WM_QUIT) break;
			//	Translate the message 
			TranslateMessage(&msg);
			//	Send message to your window procedure
			DispatchMessage(&msg);
		}

	
	return msg.message != WM_QUIT;
}

void GameWindows::ClientResize(HWND hWnd, int nWidth, int nHeight)
{
	RECT rcClient, rcWind;
	POINT ptDiff;
	GetClientRect(hWnd, &rcClient);
	GetWindowRect(hWnd, &rcWind);
	ptDiff.x = (rcWind.right - rcWind.left) - rcClient.right;
	ptDiff.y = (rcWind.bottom - rcWind.top) - rcClient.bottom;
	MoveWindow(hWnd, rcWind.left, rcWind.top, nWidth + ptDiff.x, nHeight + ptDiff.y, TRUE);
}


void GameWindows::cleanUpWindows(){

	UnregisterClass(wndClass.lpszClassName, hInstance);
}

