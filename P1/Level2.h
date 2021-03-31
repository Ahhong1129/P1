#pragma once
#include"GameState.h"

class Level2 : public GameState
{
private:
	
	/*D3DXVECTOR3 vPosition;
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
	D3DXVECTOR2 rock_position[3];
	RECT car_spriteRect;
	D3DXVECTOR2 background_position;
	D3DXVECTOR2 mainCar_position;
	D3DXVECTOR2 timer_position;
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
	float countDownTimer;
	int distance;
	bool startCount = false;
	float backPos;*/
public:
	Level2();
	~Level2();
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
};

