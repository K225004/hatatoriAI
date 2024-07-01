#pragma once
#include "../Library/gameObject.h"
#include "Player.h"
#include"ItemManager.h"

class PlayerAI : public GameObject {
public:
	PlayerAI();
	~PlayerAI();
	void SetPlayer(Player* inst);
	void Update();
	Player* player;
	ItemManager* itemmanager;
	Vector2 target;
};