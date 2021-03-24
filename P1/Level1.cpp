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
	//D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/roadbackground.jpg", D3DX_DEFAULT, D3DX_DEFAULT,
	//	D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
	//	D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(0, 255, 255),
	//	NULL, NULL, &texture1);

	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/roadbg.jpg", &background_texture);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/Maincar.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_car);

	vPosition = { 0,-7640,0 };
	
	//width = 400/ 4 = 100
	//Height = 450 / 3 = 150

	mainCarSize.x = 100;
	mainCarSize.y = 150;
	
	#HELLO

	mainCarCurrentFrame = 0;
	car_spriteRect.top = 6;
	car_spriteRect.left = 12;
	car_spriteRect.bottom = car_spriteRect.top + mainCarSize.y;
	car_spriteRect.right = car_spriteRect.left + mainCarSize.x;

	animationTimer = 0;
	animationRate = 0.3f / 4;
	animationRow = 0;
	
	scaling.x = 0.8f;
	scaling.y = 0.8f;

	mainCar_position.x = 141;
	mainCar_position.y = 450;

	background_position.x = 0;
	background_position.y = 0;

	isMainCarMoving = false;
	speed = 600.0f;
	direction.x = 0;
	direction.y = 1;
}

void Level1::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_N)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::LEVEL_1);
	}

	if (GInput::getInstance()->isKeyDown(DIK_UP))
	{
		printf("UP\n");
		animationRow = 0;
		isMainCarMoving = true;
		direction.x = 0;
		direction.y = -1;
		
	}
	
	
	if (GInput::getInstance()->isKeyDown(DIK_LEFT)) {
		printf("LEFT\n");
		animationRow = 1;
		isMainCarMoving = true;
		direction.x = -1;
		direction.y = 0;
	}

	if (GInput::getInstance()->isKeyDown(DIK_RIGHT)) {
		printf("RIGHT\n");
		animationRow = 2;
		isMainCarMoving = true;
		direction.x = 1;
		direction.y = 0;
	}
	/*else
	{
		isMainCarMoving = false;
	}*/
}

void Level1::fixedUpdate() 
{
	if (isMainCarMoving) {
		animationTimer += 1 / 60.0f;
		D3DXVECTOR2 velocity = direction * (speed / 60.0f);
		mainCar_position += velocity;
	}
	

	if (animationTimer >= animationRate) {
		animationTimer -= animationRate;
		mainCarCurrentFrame++;
		mainCarCurrentFrame %= 4;
	}

	car_spriteRect.top = animationRow * mainCarSize.y;
	car_spriteRect.left = mainCarSize.x * mainCarCurrentFrame;
	car_spriteRect.bottom = car_spriteRect.top + mainCarSize.y;
	car_spriteRect.right = car_spriteRect.left + mainCarSize.x;
	
}


void Level1::draw()
{
	D3DXVECTOR2 tempPosition = background_position;
	tempPosition.y /= 20;

	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	
	
	tempPosition.y = 300 - mainCar_position.y;
	tempPosition.y = max(max(0, tempPosition.y), -16084);
	
	D3DXVECTOR2 carOnScreen = mainCar_position + tempPosition;
	//background_position.y += speed + boostSpeed;

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &tempPosition);
	sprite->SetTransform(&mat);
	sprite->Draw(background_texture, NULL, NULL,&vPosition, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &carOnScreen);
	sprite->SetTransform(&mat);
	sprite->Draw(texture_car, &car_spriteRect,NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();
}
void Level1::release()
{
	sprite->Release();
	sprite = NULL;

	background_texture->Release();
	background_texture = NULL;

	texture_car->Release();
	texture_car = NULL;
	
}
