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
	//	Create sprite. Study the documentation. 	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &sprite);
	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &sprite);
	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/roadbackground.jpg", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(0, 255, 255),
		NULL, NULL, &texture);
	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/Maincar.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_car);


	vPosition = { 0,-200,0 };

	car_spriteRect.left = 27;
	car_spriteRect.top = 11;	
	car_spriteRect.right = 121;
	car_spriteRect.bottom = 163;

	spriteCentre = D3DXVECTOR2(0, 0);
	position = D3DXVECTOR2(100, 100);
	scaling = D3DXVECTOR2(0.8f, 0.8f);
	
}

void Level1::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_N)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::LEVEL_1);
	}


	if (GInput::getInstance()->isKeyDown(DIK_UP))
	{
		printf("UP\n");
		Car::getInstance()->mainCar_position.y += speed;
		Car::getInstance()->mainCar_position.y++;
		Car::getInstance()->direction.x = 0;
		Car::getInstance()->direction.y = -1;
	}

	if (GInput::getInstance()->isKeyDown(DIK_LEFT)) {
		printf("LEFT\n");
		Car::getInstance()->mainCar_position.x += speed;
		Car::getInstance()->mainCar_position.x++;
		Car::getInstance()->direction.x = -1;
		Car::getInstance()->direction.y = 0;
	}

	if (GInput::getInstance()->isKeyDown(DIK_RIGHT)) {
		printf("RIGHT\n");
		Car::getInstance()->mainCar_position.x -= speed;
		Car::getInstance()->mainCar_position.x--;
		Car::getInstance()->direction.x = 1;
		Car::getInstance()->direction.y = 0;
	}

}

void Level1::fixedUpdate() 
{

}


void Level1::draw()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, NULL);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, NULL, NULL,&vPosition, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCentre, rotation, &position);
	
	sprite->SetTransform(&mat);
	sprite->Draw(texture_car, &car_spriteRect, &Car::getInstance()->mainCar_position, NULL, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();
}
void Level1::release()
{
	sprite->Release();
	sprite = NULL;
	texture->Release();
	texture = NULL;
	
}