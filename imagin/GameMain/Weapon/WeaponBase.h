#pragma once
#include"../../Top/Top.h"

//プレイヤーの情報はtaskにあるので使い放題です

class WeaponBase
{
public:
//攻撃した時に呼ばれる関数
	virtual void attack() = 0;
//アップデート
	virtual void update() = 0;
//描画する関数
	virtual void draw() = 0;

private:

};

