#pragma once
#include"../../Top/Top.h"

//�v���C���[�̏���task�ɂ���̂Ŏg������ł�

class WeaponBase
{
public:
//�U���������ɌĂ΂��֐�
	virtual void attack() = 0;
//�A�b�v�f�[�g
	virtual void update() = 0;
//�`�悷��֐�
	virtual void draw() = 0;

private:

};

