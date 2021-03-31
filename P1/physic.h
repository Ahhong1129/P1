#pragma once
#include"Level1.h"
class Physic
{
private:
	static Physic* sInstance;
	Physic();
	~Physic();
public:
	static Physic* getInstance();
	static void releaseInstance();
	bool checkRockCollision(D3DXVECTOR2 pos1, RECT rect1, D3DXVECTOR2 pos2, RECT rect2);
	bool checkCarCollision(D3DXVECTOR2 pos1, RECT rect1, D3DXVECTOR2 pos3, RECT rect3);
	bool checkTruckCollision(D3DXVECTOR2 pos1, RECT rect1, D3DXVECTOR2 pos4, RECT rect4);
};

