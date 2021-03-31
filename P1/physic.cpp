#include "physic.h"
#include <stdio.h>

Physic* Physic::sInstance = NULL;

Physic::Physic()
{

}

Physic::~Physic()
{

}

Physic* Physic::getInstance()
{
	if (sInstance == NULL) {
		sInstance = new Physic;
	}
	return sInstance;
}


void Physic::releaseInstance()
{
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

bool Physic::checkRockCollision(D3DXVECTOR2 pos1, RECT rect1, D3DXVECTOR2 pos2, RECT rect2)
{
	rect1.right = pos1.x + rect1.right - rect1.left;
	rect1.left = pos1.x;
	rect1.bottom = pos1.y + rect1.bottom - rect1.top;
	rect1.top = pos1.y;

	rect2.right = pos2.x + rect2.right - rect2.left;
	rect2.left = pos2.x;
	rect2.bottom = pos2.y + rect2.bottom - rect2.top;
	rect2.top = pos2.y;


	if (rect1.bottom < rect2.top) return false;
	if (rect1.top > rect2.bottom) return false;
	if (rect1.right < rect2.left) return false;
	if (rect1.left > rect2.right) return false;

	return true;
}

bool Physic::checkCarCollision(D3DXVECTOR2 pos1, RECT rect1, D3DXVECTOR2 pos3, RECT rect3)
{
	rect1.right = pos1.x + rect1.right - rect1.left;
	rect1.left = pos1.x;
	rect1.bottom = pos1.y + rect1.bottom - rect1.top;
	rect1.top = pos1.y;

	rect3.right = pos3.x + rect3.right - rect3.left;
	rect3.left = pos3.x;
	rect3.bottom = pos3.y + rect3.bottom - rect3.top;
	rect3.top = pos3.y;


	if (rect1.bottom < rect3.top) return false;
	if (rect1.top > rect3.bottom) return false;
	if (rect1.right < rect3.left) return false;
	if (rect1.left > rect3.right) return false;

	return true;
}

bool Physic::checkTruckCollision(D3DXVECTOR2 pos1, RECT rect1, D3DXVECTOR2 pos4, RECT rect4)
{
	rect1.right = pos1.x + rect1.right - rect1.left;
	rect1.left = pos1.x;
	rect1.bottom = pos1.y + rect1.bottom - rect1.top;
	rect1.top = pos1.y;

	rect4.right = pos4.x + rect4.right - rect4.left;
	rect4.left = pos4.x;
	rect4.bottom = pos4.y + rect4.bottom - rect4.top;
	rect4.top = pos4.y;

	if (rect1.bottom < rect4.top) return false;
	if (rect1.top > rect4.bottom) return false;
	if (rect1.right < rect4.left) return false;
	if (rect1.left > rect4.right) return false;

	return true;
}





   
   
