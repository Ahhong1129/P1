#include "Level1.h"
#include"GInput.h"
#include "car.h"
#include <string>
#include "GameStateManager.h"
#include<d3d9.h>
#include<d3dx9.h>
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
	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/Maincar.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_car);

	//	Create font. Study the documentation.
	//D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 25, 0, 0, 1, false,
	//	DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
	//	DEFAULT_PITCH | FF_DONTCARE, "Arial", &font);

	vPosition = { 0,-200,0 };

	//background_spriteRect.left = 0;
	//background_spriteRect.top = 0;
	//background_spriteRect.right = 500;
	//background_spriteRect.bottom = 700;

	car_spriteRect.left = 49;
	car_spriteRect.top = 10;
	car_spriteRect.right = 111;
	car_spriteRect.bottom = 106;

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
	trans = D3DXVECTOR2(150, 150);
	scaling = D3DXVECTOR2(0.8f, 0.8f);
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, NULL);
}
void Level1::draw()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	sprite->SetTransform(&mat);
	sprite->Draw(texture, NULL, NULL,&vPosition, D3DCOLOR_XRGB(255, 255, 255));
	/*sprite->Draw(texture, NULL, NULL, &v3, D3DCOLOR_XRGB(255, 255, 255));*/

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCentre, rotation, &trans);
	
	sprite->SetTransform(&mat);
	sprite->Draw(texture_car, &car_spriteRect, &Car::getInstance()->mainCar_position, NULL, D3DCOLOR_XRGB(255, 255, 255));
	

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