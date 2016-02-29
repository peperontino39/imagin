#include "Endroll.h"

Endroll::Endroll()
{
}

void Endroll::update()
{
}

void Endroll::draw()
{
	drawFillBox(200, 0, 100, 100, Color::cyan);
}

Scene Endroll::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		return Scene::TITLE;
	}
	return Scene::ENDROLL;
}
