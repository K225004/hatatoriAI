#pragma once
#include "../Library/gameObject.h"
#include "Player.h"
#include"ItemManager.h"
#include"Item.h"

class BombManager;

class PlayerAI : public GameObject {
public:
	PlayerAI();
	~PlayerAI();
	void SetPlayer(Player* inst);
	void Update();

	void Start()override;

	Player* player;
	ItemManager* itemmanager;
	BombManager* bombManager;
	Vector2 target;
	virtual void SpownObject() {};
};