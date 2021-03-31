#include "UserGuide.h"
#include"GInput.h"
#include "GameStateManager.h"
#include<d3d9.h>
#include<d3dx9.h>
UserGuide::UserGuide()
{
}

UserGuide::~UserGuide()
{
}

void UserGuide::init()
{
	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &spriteUserGuide);
	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/userguide.png", &texture_UserGuide);

	UserGuidePosition = {0,0,0 };

}

void UserGuide::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_RETURN)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::LEVEL_1);
	}
}

void UserGuide::fixedUpdate()
{
}

void UserGuide::draw()
{
	spriteUserGuide->Begin(D3DXSPRITE_ALPHABLEND);
	D3DXMatrixTransformation2D(&matUserGuide, NULL, 0.0, NULL, NULL, NULL, NULL);
	spriteUserGuide->SetTransform(&matUserGuide);
	spriteUserGuide->Draw(texture_UserGuide, NULL, NULL, &UserGuidePosition, D3DCOLOR_XRGB(255, 255, 255));

	spriteUserGuide->End();
}

void UserGuide::release()
{
	texture_UserGuide->Release();
	texture_UserGuide = NULL;
}
