#include "Level1.h"
#include"GInput.h"
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

	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/roadbg.jpg", &background_texture);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/Maincar.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_car);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/rock.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_rock);


	vPosition = { 0,-7640,0 };

	rock_rect.top = 0;
	rock_rect.left = 0;
	rock_rect.bottom = 32;
	rock_rect.right = 32;

	rock_position.x = 150;
	rock_position.y = -500;
	
	//width = 400/ 4 = 100
	//Height = 450 / 3 = 150

	mainCarSize.x = 100;
	mainCarSize.y = 150;

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
	speed = (1.0f / animationRate) * 100;
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
	if (checkCollision(mainCar_position, car_spriteRect, rock_position, rock_rect)) {
		/*isMainCarMoving = false;*/
		D3DXVECTOR2 velocity = direction * (speed / 60.0f);
		mainCar_position -= velocity;
		velocity = -velocity;
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
	D3DXVECTOR2 tempPosition = background_position;
	tempPosition.y /= 20;
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	tempPosition.y = 300 - mainCar_position.y;
	tempPosition.y = max(max(0, tempPosition.y), -16084);
	D3DXVECTOR2 carOnScreen = mainCar_position + tempPosition;

	D3DXVECTOR2 rockOnScreen = rock_position + tempPosition;

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &tempPosition);
	sprite->SetTransform(&mat);
	sprite->Draw(background_texture, NULL, NULL,&vPosition, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &carOnScreen);
	sprite->SetTransform(&mat);
	sprite->Draw(texture_car, &car_spriteRect,NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &rockOnScreen);
	sprite->SetTransform(&mat);
	sprite->Draw(texture_rock, &rock_rect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

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

bool Level1::checkCollision(D3DXVECTOR2 pos1, RECT rect1, D3DXVECTOR2 pos2, RECT rect2)
{
	rect1.right = pos1.x + rect1.right - rect1.left;
	rect1.left = pos1.x;
	rect1.bottom = pos1.y + rect1.bottom - rect1.top;
	rect1.top = pos1.y;

	rect2.right = pos2.x + rect2.right - rect2.left;
	rect2.left = pos2.x;
	rect2.bottom = pos2.y + rect2.bottom - rect2.top;
	rect2.top = pos2.y;


	if (rect1.bottom < rect2.top) return false;
	if (rect1.top > rect2.bottom) return false;
	if (rect1.right < rect2.left) return false;
	if (rect1.left > rect2.right) return false;

	printf("Collide\n");
	return true;
}