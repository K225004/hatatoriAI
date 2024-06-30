#pragma once
#include "../Library/gameObject.h"

class Item;

class SpringAI : public GameObject {
public:
	SpringAI();
	~SpringAI();
	void Update();
	void Draw();
private:
	std::list<Item*> items;

	enum PLAYERACTION {
		PA_IDLE,
		PA_HOR_MOV_L,
		PA_HOR_MOV_R,
		PA_VER_MOV_U,
		PA_VER_MOV_D,
	};

	enum PLAYERSTATE {
		PS_DO_NOTHING,
		PS_CHASE_ITEM,
		PS_EVADE_BOMB,
		PS_UNABLE_TO_MOVE,
	};
};