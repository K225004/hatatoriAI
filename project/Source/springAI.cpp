#include "springAI.h"

SpringAI::SpringAI()
{
}

SpringAI::~SpringAI()
{
}

void SpringAI::SetPlayer(Player* inst)
{
	player = inst;
}

void SpringAI::Update()
{
	//player->Input(V2Get(1, 0));
	Vector2 closestItemPos = V2Get(0, 0);
	float closestItemDist = 0;
	for (Item* item : items) {
		if (item == nullptr) {

		}
		else {

		}
	}
}