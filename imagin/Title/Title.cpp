#include "Title.h"

Title::Title()
{
}

void Title::update()
{
}

void Title::draw()
{
	drawFillBox(0, 0, 100, 100, Color::white);
}

Scene Title::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		return Scene::GAMEMAIN;
	}
	return Scene::TITLE;
}
