#include "GGraphic.h"
#include"GameWindows.h"
#include<d3d9.h>
#include<d3dx9.h>

GGraphic* GGraphic::sInstance = NULL;

GGraphic* GGraphic::getInstance() {

	if (sInstance == NULL) {
		sInstance = new GGraphic;
	}
	return sInstance;
}

void GGraphic::releaseInstance() {
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

GGraphic::GGraphic()
{
	//	Define Direct3D 9.
	 direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	//	Define how the screen presents.
	
	ZeroMemory(&d3dPP, sizeof(d3dPP));

	//	Refer to Direct3D 9 documentation for the meaning of the members.
	d3dPP.Windowed = true;
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = 430;
	d3dPP.BackBufferHeight = 600;
	d3dPP.hDeviceWindow = GameWindows::getInstance()->g_hWnd;


	////	Create a Direct3D 9 device.
	HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GameWindows::getInstance()->g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);

}

GGraphic::~GGraphic()
{
	//	Release the device when exiting.
	d3dDevice->Release();
	//	Reset pointer to NULL, a good practice.
	d3dDevice = NULL;
}
void GGraphic::begin() {
	//	Clear the back buffer.
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	//	Begin the scene
	d3dDevice->BeginScene();
}
void  GGraphic::end() {
	//	End the scene
	d3dDevice->EndScene();
	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}
