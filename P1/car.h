#pragma once
#include<d3dx9.h>

class Car
{
private:
	Car();
	~Car();
	static Car* sInstance;
public:
	D3DXVECTOR3 mainCar_position;
	static Car* getInstance();
	static void releaseInstance();
};
