#pragma once
#include"../Top/Top.h"
#include"../SceneBase/SceneBase.h"

/*
�Z���X�̂����^�C�g����҂��Ă���
*/

class Title : public SceneBase
{
public:
	Title();
	void update() override;
	void draw() override;
	Scene shift() override;
private:
	
};

