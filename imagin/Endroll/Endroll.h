#pragma once
#include"../Top/Top.h"
#include"../SceneBase/SceneBase.h"

/*
�Z���X�̂����G���h��҂��Ă���
*/

class Endroll : public SceneBase
{
public:
	Endroll();
	void update() override;
	void draw() override;
	Scene shift() override;
private:

};
