#include "Menu.h"
#include"GInput.h"
#include "GameStateManager.h"
#include<d3d9.h>
#include<d3dx9.h>
Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init()
{
	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &spriteMenu);
	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/Racing background.jpg", &texture_menu);

	D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 30, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Showcard Gothic", &menu_font);

	menuPosition = {-58,0,0 };

	menuRect.left = 300;
	menuRect.top = 300;
	menuRect.right = 100;
	menuRect.bottom = 100;
}

void Menu::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_SPACE)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::USERGUIDE);
	}

}

void Menu::fixedUpdate()
{
}

void Menu::draw()
{
	spriteMenu->Begin(D3DXSPRITE_ALPHABLEND);
	D3DXMatrixTransformation2D(&matMenu, NULL, 0.0, NULL, NULL, NULL, NULL);
	spriteMenu->SetTransform(&matMenu);
	spriteMenu->Draw(texture_menu, NULL, NULL, &menuPosition, D3DCOLOR_XRGB(255, 255, 255));

	menu_font->DrawText(spriteMenu, "Press space to start", -1, &menuRect, DT_NOCLIP | DT_CENTER , D3DCOLOR_XRGB(255, 0, 255));

	spriteMenu->End();
}

void Menu::release()
{
	texture_menu->Release();
	texture_menu = NULL;

	menu_font->Release();
	menu_font = NULL;
}
