#include "car.h"
#include<stdio.h>
#include "GInput.h"
Car* Car::sInstance = 0;

Car::Car()
{
	//121 91
	mainCar_position = { 0,-260,0 };
}

Car::~Car()
{
}

Car* Car::getInstance()
{
	if (sInstance == 0) {
		sInstance = new Car;
	}
	return sInstance;
}

void Car::releaseInstance()
{
	if (sInstance != 0) {
		delete sInstance;
		sInstance = 0;
	}
}


