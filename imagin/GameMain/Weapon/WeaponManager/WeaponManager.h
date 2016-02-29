#pragma once
#include"../WeaponBase.h"

class WeaponManager
{
public:
	static void set(WeaponBase& _weapon) {
		*weapon = _weapon;
	}
	static WeaponBase& get() {
		return *weapon;
	}
private:
	static std::shared_ptr<WeaponBase> weapon;
};
