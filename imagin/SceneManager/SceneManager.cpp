#include "SceneManager.h"

SceneManager::SceneManager()
{
	scene = std::make_shared<Title>();
}

SceneManager::~SceneManager()
{
}

void SceneManager::update()
{
	scene->update();
}

void SceneManager::draw()
{
	scene->draw();
}

void SceneManager::shift()
{
	if (scene_num != scene->shift()) {
		switch (scene->shift() == Scene::AGEIN ?
			scene_num : scene->shift())
		{
		case Scene::TITLE:
			scene = std::make_shared<Title>();
			break;
		case Scene::GAMEMAIN:
			scene = std::make_shared<GameMain>();
			break;
		case Scene::ENDROLL:
			scene = std::make_shared<Endroll>();
			break;
		}
		scene_num = scene->shift();
	}
}
