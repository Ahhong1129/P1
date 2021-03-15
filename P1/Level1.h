#pragma once
#include "GameState.h"
#include "GGraphic.h"
class Level1 : public GameState
{
private:
	LPDIRECT3DTEXTURE9 texture;
	LPDIRECT3DTEXTURE9 texture_car;
	LPD3DXSPRITE sprite;
	D3DXMATRIX mat;
	RECT spriteRect;
	RECT spriteRect1;
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


