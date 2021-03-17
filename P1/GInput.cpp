#include "GInput.h"
#include "GameWindows.h"
#include <dinput.h>
GInput* GInput::sInstance = NULL;

GInput* GInput::getInstance() {
	if (sInstance == NULL) {
		sInstance = new GInput;
	}
	return sInstance;
}

void GInput::releaseInstance() {
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

GInput::GInput()
{
	DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);
	dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);
	dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	dInputKeyboardDevice->SetCooperativeLevel(GameWindows::getInstance()->g_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	ZeroMemory(diKeys, sizeof(diKeys));
}

GInput::~GInput()
{
	dInputKeyboardDevice->Unacquire();
	dInputKeyboardDevice->Release();
	dInputKeyboardDevice = NULL;
	dInput->Release();
	dInput = NULL;

}
void GInput::update()
{
	result = dInputKeyboardDevice->GetDeviceState(sizeof(diKeys), (LPVOID)&diKeys);
	if (FAILED(result))
	{
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED)) {
			dInputKeyboardDevice->Acquire();
		}
	}
}
bool GInput::isKeyDown(int index) {
	return diKeys[index] & 0x80;
}
