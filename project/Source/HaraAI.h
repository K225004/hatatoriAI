#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"

namespace {
	static const int SEARCH_NEAR = 200;	//サーチ	半径
	static const int ADJUSTMENT_DISTANCE = 300;	//調整が入る距離のライン
}

class HaraAI : public PlayerAI {
public:
	HaraAI();
	~HaraAI();
	void Update();
	void Draw();
private:
	void Set();

	float distance;
};