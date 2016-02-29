#pragma once
#include"../Top/Top.h"
#include"../SceneBase/SceneBase.h"

/*
センスのいいタイトルを待っている
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

