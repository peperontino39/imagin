#pragma once
#include "../../../Top/Top.h"
#include "../EnemyBase.h"

/*
�G�l�~�[�N���X
pushback����֐������̓}�b�v�ԍ�
update�ł�ai�̏������ꏏ�ɂ���ė~����
�G�l�~�[�x�[�X���p���������̂��ʒu�����߂�pushback����
�p���������ɓG�ɂ���ăT�C�Y�Ƃ�update(AI)�Ȃǂ��I�[�o�[���C�h����
*/


class EnemyHolder
{
public:
	EnemyHolder();
	~EnemyHolder();

private:
	std::list<std::shared_ptr<EnemyBase>> enemy;
};
