#pragma once
#include"GameState.h"
#include <vector>
class GameStateManager
{
private:
	GameStateManager();
	~GameStateManager();
	static GameStateManager* sInstance;
	std::vector<GameState*>gameStateList;
	GameState* currentGameState;
public:
	enum GAMESTATENAME {
		LEVEL_1,
		LEVEL_2
	};

	static GameStateManager* getInstance();
	static void releaseInstance(); 

	void update();
	void draw();
	void changeGameState(int index);
};

