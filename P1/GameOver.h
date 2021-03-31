#pragma once
#include "GameState.h"
#include "GGraphic.h"
#include<d3d9.h>
#include<d3dx9.h>
class GameOver : public GameState
{
public:
	GameOver();
	~GameOver();

	LPD3DXSPRITE spriteGameOver;
	LPDIRECT3DTEXTURE9 texture_GameOver;
	D3DXMATRIX matGameOver;
	LPD3DXFONT GameOver_font;
	D3DXVECTOR3 GameOverPosition;
	RECT GameOverRect;
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
};

