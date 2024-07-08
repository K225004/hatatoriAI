#include "PlayerAI.h"
#include "bombManager.h"

PlayerAI::PlayerAI(){
	itemmanager = nullptr;
	bombManager = nullptr;
}

void PlayerAI::Start() {
	itemmanager = FindGameObject<ItemManager>();
	bombManager = FindGameObject<BombManager>();
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
