#pragma once
#include <dinput.h>
class GInput
{
private:
	BYTE  diKeys[256];
	LPDIRECTINPUT8 dInput;
	LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
	HRESULT result;
	GInput();
	~GInput();
	static GInput* sInstance;
public:
	static GInput* getInstance();
	static void releaseInstance();
	void update();
	bool isKeyDown(int index);
};

