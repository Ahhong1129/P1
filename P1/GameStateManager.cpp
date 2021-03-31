#include "GameStateManager.h"
#include "Menu.h"
#include "Level1.h"
#include"Level2.h"
#include"GameOver.h"
#include"UserGuide.h"
#include"WinCondition.h"
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
	Menu* menu = new Menu();
	menu->init();

	Level1* level1 = new Level1();
	level1->init();

	Level2* level2 = new Level2();
	level2->init();

	GameOver* gameOver = new GameOver();
	gameOver->init();

	UserGuide* userGuide = new UserGuide();
	userGuide->init();

	WinCondition* win = new WinCondition();
	win->init();

	gameStateList.push_back(menu);
	gameStateList.push_back(level1);
	gameStateList.push_back(level2);
	gameStateList.push_back(gameOver);
	gameStateList.push_back(userGuide);
	gameStateList.push_back(win);

	//Default
	currentGameState = menu;

	gTimer = new GTimer();
	gTimer->init(60);
}

GameStateManager::~GameStateManager()
{
	delete gTimer;
	gTimer = NULL;

	for (int i = 0; i < gameStateList.size(); i++) {
		delete gameStateList[1];
		gameStateList[i] = NULL;
	}
}

void GameStateManager::update() 
{
	int frameToUpdate = gTimer->frameToUpdate();
	currentGameState->update();
	for (int i = 0; i < frameToUpdate; i++) 
	{
		currentGameState->fixedUpdate();
	}
	
}
void GameStateManager::draw()
{
	currentGameState->draw();
}

void GameStateManager::changeGameState(int index)
{
	currentGameState = gameStateList[index];
}
