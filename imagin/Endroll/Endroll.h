#pragma once
#include"../Top/Top.h"
#include"../SceneBase/SceneBase.h"

/*
センスのいいエンドを待っている
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
