#pragma once
#include"../Top/Top.h"
#include"../SceneBase/SceneBase.h"

class GameMain : public SceneBase
{
public:
	GameMain();
	void update() override;
	void draw() override;
	Scene shift() override;
private:

};