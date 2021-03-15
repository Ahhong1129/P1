#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>
#include <iostream>
class GameWindows
{
private: 
	static GameWindows* sInstance;
	GameWindows();
	~GameWindows();

public:
	HWND g_hWnd;
	//	Window's structure
	WNDCLASS wndClass;
	//Window Handle
	HINSTANCE hInstance;

	static GameWindows* getInstance();
	static void releaseInstance();

	void init();
	bool isWindowsRunning();
	void cleanUpWindows();

	static int keyPressed;
	static int mouseX, mouseY;

	void ClientResize(HWND hWhd, int nwidth, int nheight);
};

