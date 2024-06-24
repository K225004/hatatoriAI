#include "PlayerAI.h"

PlayerAI::PlayerAI()
{
}

PlayerAI::~PlayerAI()
{
}

void PlayerAI::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAI::Update()
{
	player->Input(V2Get(1, 0));
}
