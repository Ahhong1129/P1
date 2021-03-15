#include "GameWindows.h"
#include"GGraphic.h"
#include "GInput.h"
#include"GameStateManager.h"

//	use int main if you want to have a console to print out message
int main()
//	use WinMain if you don't want the console
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	GameWindows* gWin = GameWindows::getInstance();

	gWin->init();

	GGraphic* gGraphic = GGraphic::getInstance();
	GInput* gInput = GInput::getInstance();
	GameStateManager* gameStateManager = GameStateManager::getInstance();

	while (gWin->isWindowsRunning())
	{
		gInput->update();

		gameStateManager->update();
		
		int x = 0;
		if (gInput->isKeyDown(DIK_UP))
		{
			printf("UP\n");
		}

		if (gInput->isKeyDown(DIK_LEFT)) {//left
			printf("LEFT\n");
			x++;
		}
		if (gInput->isKeyDown(DIK_RIGHT)) {//right
			printf("RIGHT\n");
			x--;
		}
		//if (gWin->keyPressed == 70 && d3dPP.Windowed == true)
		//{
			//d3dPP.Windowed = false;
			//gGraphic->d3dDevice->Reset(&d3dPP);
		//}
		//else if (gWin->keyPressed == 69 && d3dPP.Windowed == false) {

			//d3dPP.Windowed = true;
			//gGraphic->d3dDevice->Reset(&d3dPP);
		//}
	

		gGraphic->begin();

		gameStateManager->draw();


		gGraphic->end();
	}

	gameStateManager->releaseInstance();

	gWin->releaseInstance();
	gGraphic->releaseInstance();
	gInput->releaseInstance();
	

	return 0;
}
//--------------------------------------------------------------------

