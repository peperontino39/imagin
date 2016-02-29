#pragma once

#include "../../lib/framework.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

//画面サイズ
enum Window {
	WIDTH = 1920,
	HEIGHT = 1080
};

//AppEnvシングルトン
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

//ランダムのシングルトン
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

