#pragma once
#include "GameState.h"
#include "GGraphic.h"
#include<d3d9.h>
#include<d3dx9.h>
class Menu : public GameState
{
public:
	Menu();
	~Menu();
	LPD3DXSPRITE spriteMenu;
	LPDIRECT3DTEXTURE9 texture_menu;
	D3DXMATRIX matMenu;
	LPD3DXFONT menu_font;
	D3DXVECTOR3 menuPosition;
	RECT menuRect;
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
};

