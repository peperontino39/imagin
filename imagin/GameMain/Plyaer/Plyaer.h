#pragma once
#include "../CharacterBase/CharacterBase.h"

/*
��̂͂����Ɠ�������
������}�l�[�W���[
player�̏����}�l�[�W���[
��邱�Ƃ�HP�Ƃ��̃X�e�[�^�X���ł��邩������Ȃ�
�U����������true��Ԃ��֐��Ƃ�����
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
