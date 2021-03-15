#include "GameStateManager.h"
#include "Level1.h"
#include"Level2.h"
GameStateManager* GameStateManager::sInstance = 0;

GameStateManager* GameStateManager::getInstance() {

	if (sInstance == 0) {
		sInstance = new GameStateManager();
	}
	return sInstance;
} 
void GameStateManager::releaseInstance() {
	if (sInstance != 0) {
		delete sInstance;
		sInstance = 0;
	}
}

GameStateManager::GameStateManager()
{

	Level1* level1 = new Level1();
	level1->init();

	Level2* level2 = new Level2();
	level2->init();

	gameStateList.push_back(level1);
	gameStateList.push_back(level2);

	//Default
	currentGameState = level1;

}

GameStateManager::~GameStateManager()
{
	for (int i = 0; i < gameStateList.size(); i++) {
		delete gameStateList[1];
		gameStateList[i] = NULL;
	}
}

void GameStateManager::changeGameState(int index)
{
	currentGameState = gameStateList[index];
}

void GameStateManager::update() {
	currentGameState->update();
}
void GameStateManager::draw() {
	currentGameState->draw();
}
