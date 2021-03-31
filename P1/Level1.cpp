#include "Level1.h"
#include"GInput.h"
#include"physic.h"
#include <string>
#include<iostream>
#include "GameStateManager.h"
#include<d3d9.h>
#include<d3dx9.h>

using namespace std;

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

	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/roadbg.jpg", &background_texture);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/Maincar.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_car);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/rock.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_rock);

	D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 25, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &time_font);

	rockSize.x = 40;
	rockSize.y = 48;

	rock_rect.top = 0;
	rock_rect.left = 0;
	rock_rect.bottom = rock_rect.top + rockSize.y;
	rock_rect.right = rock_rect.bottom + rockSize.x;
	
	timeRect.left = 0;
	timeRect.top = 0;
	timeRect.right = 100;
	timeRect.bottom = 100;

	rock_position[0].x = 250;
	rock_position[0].y = 100;

	rock_position[1].x = 150;
	rock_position[1].y = -200;

	rock_position[2].x = 250;
	rock_position[2].y = -600;

	rock_position[3].x = 150;
	rock_position[3].y = -1000;

	rock_position[4].x = 250;
	rock_position[4].y = -3000;

	//width = 400/ 4 = 100
	//Height = 450 / 3 = 150

	mainCarSize.x = 100;
	mainCarSize.y = 150;

	mainCarCurrentFrame = 0;

	car_spriteRect.top = 0;
	car_spriteRect.left = 0;
	car_spriteRect.bottom = car_spriteRect.top + mainCarSize.y;
	car_spriteRect.right = car_spriteRect.left + mainCarSize.x;

	animationTimer = 0;
	animationRate = 0.3f / 4;
	animationRow = 0;
	
	scaling.x = 0.8f;
	scaling.y = 0.8f;

	mainCar_position.x = 141;
	mainCar_position.y = 300;

	background_position[0].x = 0;
	background_position[0].y = -1024 + 600;

	background_position[1].x = 0;
	background_position[1].y = -1024 + 600 - 1024;

	isMainCarMoving = false;
	speed = (1.0f / animationRate) * 100;
	direction.x = 0;
	direction.y = 1;

	countDownTimer = 10;

	bgLength = 15000;
}

void Level1::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_N)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::LEVEL_1);
	}

	if (GInput::getInstance()->isKeyDown(DIK_UP))
	{
		printf("UP\n");
		startCount = true;
		animationRow = 0;
		isMainCarMoving = true;
		direction.x = 0;
		direction.y = -1;
		
	}
	
	else if (GInput::getInstance()->isKeyDown(DIK_LEFT)) {
		printf("LEFT\n");
		animationRow = 1;
		isMainCarMoving = true;
		direction.x = -1;
		direction.y = 0;
	}

	else if (GInput::getInstance()->isKeyDown(DIK_RIGHT)) {
		printf("RIGHT\n");
		animationRow = 2;
		isMainCarMoving = true;
		direction.x = 1;
		direction.y = 0;
	}
	else
	{
		isMainCarMoving = false;
	}
	//512 //32768
}

void Level1::fixedUpdate() 
{
	for (int i = 0; i < 5; i++) 
	{
		if (Physic::getInstance()->checkRockCollision(mainCar_position, car_spriteRect, rock_position[i], rock_rect)) {
			/*isMainCarMoving = false;*/
			D3DXVECTOR2 velocity = direction * (speed / 60.0f);
			mainCar_position -= velocity;
			velocity = -velocity;
		}
	}

	if (startCount) {
		countDownTimer -= (1 / 60.0);
	}
	

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
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	float backPos = (600 / 2) - mainCar_position.y;
	backPos = min(max(backPos, 300 - 150), bgLength);

	for (int i = 0; i < 2; i++) {
		D3DXVECTOR2 temp = background_position[i];
		temp.y += (backPos - 300 + 36);

		if (temp.y >= 600) {
			background_position[i].y -= 2048;
		}
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &temp);
		sprite->SetTransform(&mat);
		sprite->Draw(background_texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}
	D3DXVECTOR2 carOnScreen = mainCar_position;
	carOnScreen.y = (mainCar_position.y) + backPos;

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &carOnScreen);
	sprite->SetTransform(&mat);
	sprite->Draw(texture_car, &car_spriteRect,NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, NULL);
	sprite->SetTransform(&mat);
	string timeStr = "Time Remaining: " + to_string(countDownTimer);

	if (countDownTimer > 0) {
		time_font->DrawText(sprite, timeStr.c_str(), -1, &timeRect, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
	}
	

	for (int i = 0; i < 5; i++) {
		D3DXVECTOR2 rockOnScreen = rock_position[i];
		rockOnScreen.y = (rock_position[i].y) + backPos;
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &rockOnScreen);
		sprite->SetTransform(&mat);
		sprite->Draw(texture_rock, &rock_rect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}
	
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

	texture_rock->Release();
	texture_rock = NULL;
}
