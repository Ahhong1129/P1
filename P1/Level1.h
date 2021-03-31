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
	LPD3DXFONT time_font;
	LPD3DXFONT end_font;
	LPD3DXSPRITE sprite;
	D3DXMATRIX mat;
	RECT timeRect;
	RECT endRect;
	RECT rock_rect;
	RECT truck_rect;
	D3DXVECTOR2 rock_position[5];
	RECT car_spriteRect;
	D3DXVECTOR2 background_position[2];
	D3DXVECTOR2 mainCar_position;
	D3DXVECTOR2 timer_position;
	D3DXVECTOR2 scaling;
	D3DXVECTOR2 direction;
	D3DXVECTOR2 mainCarSize;
	D3DXVECTOR2 rockSize;
	int mainCarCurrentFrame;
	float animationRate;
	float animationTimer;
	int animationRow;
	bool isMainCarMoving;
	float speed;
	float countDownTimer;
	int distance;
	bool startCount = false;
	float bgLength;
public: 
	Level1();
	~Level1();
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
	
};


