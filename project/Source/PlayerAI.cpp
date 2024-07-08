#include "PlayerAI.h"

PlayerAI::PlayerAI(){
}

void PlayerAI::Start() {
	itemmanager = FindGameObject<ItemManager>();
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

}
