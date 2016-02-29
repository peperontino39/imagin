#include "GameMain.h"

GameMain::GameMain()
{
}

void GameMain::update()
{
}

void GameMain::draw()
{
	drawFillBox(100, 0, 100, 100, Color::blue);
}

Scene GameMain::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		return Scene::ENDROLL;
	}
	return Scene::GAMEMAIN;
}
