#pragma once
#include "../../../Top/Top.h"
#include "../EnemyBase.h"

/*
エネミークラス
pushbackする関数引数はマップ番号
updateではaiの処理も一緒にやって欲しい
エネミーベースを継承したものを位置を決めてpushbackする
継承した時に敵によってサイズとかupdate(AI)などをオーバーライドする
*/


class EnemyHolder
{
public:
	EnemyHolder();
	~EnemyHolder();

private:
	std::list<std::shared_ptr<EnemyBase>> enemy;
};
