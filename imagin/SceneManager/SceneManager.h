#pragma once
#include "../Top/Top.h"
#include "../SceneBase/SceneBase.h"
#include "../Title/Title.h"
#include "../GameMain/GameMain.h"
#include "../Endroll/Endroll.h"


class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void update();
	void draw();
	void shift();

private:
	std::shared_ptr<SceneBase> scene;
	Scene scene_num;
};