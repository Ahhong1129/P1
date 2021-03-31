#pragma once
#include "GameState.h"
#include "GGraphic.h"
#include<d3d9.h>
#include<d3dx9.h>

class UserGuide : public GameState
{
public:
	UserGuide();
	~UserGuide();
	LPD3DXSPRITE spriteUserGuide;
	LPDIRECT3DTEXTURE9 texture_UserGuide;
	D3DXMATRIX matUserGuide;
	D3DXVECTOR3 UserGuidePosition;
	RECT UserGuideRect;
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
};

