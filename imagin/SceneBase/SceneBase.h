#pragma once
#include "../Top/Top.h"

enum class Scene {
	TITLE,
	GAMEMAIN,
	ENDROLL,
	AGEIN
};


class SceneBase
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual Scene shift() = 0;
private:

};


