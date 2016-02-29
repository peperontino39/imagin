#pragma once
#include "../CharacterBase/CharacterBase.h"



class TaskManager
{
public:
	static void set(std::string _Key, CharacterBase& _character) {
		if (character.find(_Key) == character.end()) {
			*character[_Key] = _character;
		}
	};
	static CharacterBase& get(std::string _Key) {
		return *character[_Key];
	};

private:
	static std::unordered_map<std::string, std::shared_ptr<CharacterBase>> character;
};
