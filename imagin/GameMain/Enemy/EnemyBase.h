#pragma once
#include "../../Top/Top.h"
#include "../CharacterBase/CharacterBase.h"



class EnemyBase : public CharacterBase
{
public:
	EnemyBase(Vec2f _pos) {
		Vec2f pos = _pos;
		Vec2f vec = Vec2f::Zero();
	}
	virtual void update() = 0;
	virtual void draw() = 0;

private:
	Vec2f pos;
	Vec2f size;
	Vec2f vec;
};
