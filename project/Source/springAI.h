#pragma once
#include "../Library/gameObject.h"
#include "Player.h"
#include"PlayerAI.h"


class Item;

class SpringAI : public PlayerAI {
public:
	SpringAI();
	~SpringAI();
	void Update();
	void Draw();
private:
	PlayerAI* playerAI;
	std::list<Item*> items;

	VECTOR onChaseItemPos;

	enum PLAYERACTION {
		PA_IDLE,
		PA_HOR_MOV_L,
		PA_HOR_MOV_R,
		PA_VER_MOV_U,
		PA_VER_MOV_D,
	};

	PLAYERACTION pAction;

	enum PLAYERSTATE {
		PS_DO_NOTHING,
		PS_CHASE_ITEM,
		PS_EVADE_BOMB,
		PS_UNABLE_TO_MOVE,
	};
};