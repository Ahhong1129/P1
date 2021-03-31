#pragma once
#include "GameState.h"
#include "GGraphic.h"
#include<d3d9.h>
#include<d3dx9.h>
class WinCondition : public GameState
{
public:
	WinCondition();
	~WinCondition();

	LPD3DXSPRITE spriteWin;
	LPDIRECT3DTEXTURE9 texture_win;
	D3DXMATRIX matWin;
	D3DXVECTOR3 winPosition;
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
};

