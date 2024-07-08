#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"

namespace {
	static const float MAGNIFICATION = 0.1f;
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