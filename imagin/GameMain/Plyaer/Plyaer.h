#pragma once
#include "../CharacterBase/CharacterBase.h"

/*
大体はいつもと同じ処理
武器もマネージャー
playerの情報もマネージャー
やることはHPとかのステータスができるかもしれない
攻撃した時にtrueを返す関数とかかな
*/


class Player : public CharacterBase
{
public:
	Player();
	~Player();

	Vec2f& getPos() override;
	Vec2f& getSize()override;
	Vec2f& getVec()override;

	void update();
	void draw();

private:
	Vec2f pos;
	Vec2f size;
	Vec2f vec;
};
