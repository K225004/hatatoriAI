#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"

namespace {
	static const int SEARCH_NEAR = 200;	//�T�[�`	���a
	static const int ADJUSTMENT_DISTANCE = 300;	//���������鋗���̃��C��
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