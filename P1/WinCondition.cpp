#include "WinCondition.h"
#include"GInput.h"
#include "GameStateManager.h"
#include<d3d9.h>
#include<d3dx9.h>
WinCondition::WinCondition()
{
}

WinCondition::~WinCondition()
{
}

void WinCondition::init()
{
	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &spriteWin);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/win.jpg", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_win);

	
}

void WinCondition::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_Y)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::LEVEL_2);
	}

	if (GInput::getInstance()->isKeyDown(DIK_N)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::MENU);
	}
}

void WinCondition::fixedUpdate()
{
}

void WinCondition::draw()
{
	spriteWin->Begin(D3DXSPRITE_ALPHABLEND);
	D3DXMatrixTransformation2D(&matWin, NULL, 0.0, NULL, NULL, NULL, NULL);
	spriteWin->SetTransform(&matWin);
	spriteWin->Draw(texture_win, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	spriteWin->End();
}

void WinCondition::release()
{
	texture_win->Release();
	texture_win = NULL;
}
