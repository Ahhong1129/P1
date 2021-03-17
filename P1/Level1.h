#pragma once
#include "GameState.h"
#include "GGraphic.h"
#include<d3d9.h>
#include<d3dx9.h>
class Level1 : public GameState
{
private:
	D3DXVECTOR3 vPosition;
	LPDIRECT3DTEXTURE9 texture;
	LPDIRECT3DTEXTURE9 texture_car;
	LPD3DXSPRITE sprite;
	D3DXMATRIX mat;
	RECT background_spriteRect;
	RECT car_spriteRect;
	/*RECT spriteRect_car;*/
	///RECT textRect;
	//LPD3DXFONT font;
	D3DXVECTOR2 spriteCentre;
	D3DXVECTOR2 trans;
	D3DXVECTOR2 scaling;
	float rotation = 0;
	int x = 0;

public: 
	Level1();
	~Level1(); 
	void init();
	void update();
	void draw();
	void release();
	
};


