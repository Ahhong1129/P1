#include "Level1.h"
#include"GInput.h"
#include <string>
#include "GameStateManager.h"
Level1::Level1()
{
}

Level1::~Level1()
{
}

void Level1::init() 
{
	//	Create sprite. Study the documentation. 
	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &sprite);
	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/background.jpg", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(0, 255, 255),
		NULL, NULL, &texture);
	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/mustang.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(0, 255, 255),
		NULL, NULL, &texture_car);

	//	Create font. Study the documentation.
	//D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 25, 0, 0, 1, false,
	//	DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
	//	DEFAULT_PITCH | FF_DONTCARE, "Arial", &font);


	spriteRect.left = 72;
	spriteRect.top = 58;
	spriteRect.right = 174;
	spriteRect.bottom = 223;

	/*
	 textRect.left = 0;
	 textRect.top = 0;
	 textRect.right = 200;
	 textRect.bottom = 100;*/

}

void Level1::update() 
{
	if (GInput::getInstance()->isKeyDown(DIK_N)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::LEVEL_1);
	}

	spriteCentre = D3DXVECTOR2(0, 0);
	trans = D3DXVECTOR2(0, 0);
	scaling = D3DXVECTOR2(1.0f, 1.0f);
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, NULL);
}
void Level1::draw() 
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	sprite->SetTransform(&mat);
	sprite->Draw(texture, NULL, NULL, &D3DXVECTOR3(0, 0, 0), D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCentre, rotation, &trans);

	sprite->SetTransform(&mat);
	sprite->Draw(texture_car, &spriteRect, &D3DXVECTOR3(x, 0, 0) , NULL, D3DCOLOR_XRGB(255, 255, 255));
	

	//font->DrawText(sprite, "Hello World!", -1, &textRect, DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));
	sprite->End();
}
void Level1::release() 
{
	sprite->Release();
	sprite = NULL;
	texture->Release();
	texture = NULL;
	//font->Release();
	//font = NULL;
}
