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
	for (Item* item : items) {

	}
}