#pragma once

#include "../../lib/framework.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

//��ʃT�C�Y
enum Window {
	WIDTH = 1920,
	HEIGHT = 1080
};

//AppEnv�V���O���g��
class App
{
public:
	static AppEnv& get()
	{
		static AppEnv _env(Window::WIDTH, Window::HEIGHT
			, false, true
			);
		return _env;
	}
};

#define env App::get()

//�����_���̃V���O���g��
class Rand
{
public:
	static Random& get()
	{
		static Random _rand;
		return _rand;
	}
};

#define rand Rand::get()

