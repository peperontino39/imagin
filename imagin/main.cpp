#include "Top/Top.h"
#include "SceneManager/SceneManager.h"

#include "GameMain/TaskManager/TaskManager.h"


int main() {

	

	SceneManager scenemanager;


	while (env.isOpen()) {
		env.begin();

		auto start = std::chrono::system_clock::now();

		scenemanager.update();
		scenemanager.shift();
		scenemanager.draw();

		auto end = std::chrono::system_clock::now();
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		std::cout << "sec " << msec << std::endl;

		env.end();
	}
}
