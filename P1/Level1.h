#pragma once
#include "GameState.h"
#include "GGraphic.h"
#include<d3d9.h>
#include<d3dx9.h>
class Level1 : public GameState
{
private:
	D3DXVECTOR3 vPosition;
	LPDIRECT3DTEXTURE9 background_texture;
	LPDIRECT3DTEXTURE9 texture_car;
	LPDIRECT3DTEXTURE9 texture_rock;
	LPD3DXSPRITE sprite;
	D3DXMATRIX mat;
	RECT rock_rect; 
	RECT car_spriteRect;
	D3DXVECTOR2 background_position;
	D3DXVECTOR2 mainCar_position;
	D3DXVECTOR2 rock_position;
	D3DXVECTOR2 scaling;
	D3DXVECTOR2 direction;
	D3DXVECTOR2 mainCarSize;
	int boostSpeed = 0;
	int mainCarCurrentFrame;
	float animationRate;
	float animationTimer;
	int animationRow;
	bool isMainCarMoving;
	float speed;
	bool checkCollision(D3DXVECTOR2 pos1, RECT rect1, D3DXVECTOR2 pos2, RECT rect2);
public: 
	Level1();
	~Level1(); 
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
	
};


