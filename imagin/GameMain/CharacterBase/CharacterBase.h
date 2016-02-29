#pragma once
#include "../../Top/Top.h"

class CharacterBase
{
public:
	virtual Vec2f& getPos() = 0;
	virtual Vec2f& getSize() = 0;
	virtual Vec2f& getVec() = 0;
private:

};

