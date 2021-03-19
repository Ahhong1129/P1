#pragma once
#include"GameState.h"
class Level2 : public GameState
{
public:
	Level2();
	~Level2();

	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
};

