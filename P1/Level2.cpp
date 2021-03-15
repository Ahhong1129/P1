#include "Level2.h"
#include"GInput.h"
#include "GameStateManager.h"
Level2::Level2()
{
}

Level2::~Level2()
{
}

void Level2::init()
{
}

void Level2::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_B)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::LEVEL_2);
	}
}

void Level2::draw()
{
}

void Level2::release()
{
}
