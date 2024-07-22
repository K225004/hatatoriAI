#include "springAI.h"
#include "Item.h"

SpringAI::SpringAI()
{
	playerAI = dynamic_cast<PlayerAI*>(playerAI);
	pAction = PLAYERACTION::PA_IDLE;
}

SpringAI::~SpringAI()
{
}

void SpringAI::Update()
{
	//player->Input(Vector2(1,1));
	items = FindGameObjects<Item>();
	//player->Input(V2Get(1, 0));
	VECTOR closestItemPos = VGet(0.0f, 0.0f, 0.0f);
	float closestItemX = 0.0f;
	float closestItemY = 0.0f;
	float closestItemZ = 0.0f;
	float closestItemDist = 9999;
	for (Item* i : items) {
		if (i == nullptr) {

		}
		else {
			if (VSize(VSub(VGet(i->GetPosition().x, i->GetPosition().y, 0.0f),
				VGet(player->Position().x, player->Position().y, 0.0f))) < closestItemDist) {
				closestItemDist = VSize(VSub(VGet(i->GetPosition().x, i->GetPosition().y, 0.0f),
					VGet(player->Position().x, player->Position().y, 0.0f)));
				closestItemPos = VGet(i->GetPosition().x, i->GetPosition().y, 0.0f);
			}
		}
	}

	onChaseItemPos = closestItemPos;
	if (onChaseItemPos.x + 16.0f <= player->Position().x || onChaseItemPos.x - 16.0f >= player->Position().x) {
		if (onChaseItemPos.x + 16.0f < player->Position().x) {
			pAction = PLAYERACTION::PA_HOR_MOV_L;
		}
		else if (onChaseItemPos.x - 16.0f > player->Position().x) {
			pAction = PLAYERACTION::PA_HOR_MOV_R;
		}
	}
	else {
		if (onChaseItemPos.y < player->Position().y) {
			pAction = PLAYERACTION::PA_VER_MOV_U;
		}
		else if (onChaseItemPos.y > player->Position().y) {
			pAction = PLAYERACTION::PA_VER_MOV_D;
		}
	}

	switch (pAction) {
	case PLAYERACTION::PA_IDLE:
		break;
	case PLAYERACTION::PA_HOR_MOV_L:
	case PLAYERACTION::PA_HOR_MOV_R:
	case PLAYERACTION::PA_VER_MOV_U:
	case PLAYERACTION::PA_VER_MOV_D:
		player->Input(V2Get(onChaseItemPos.x, onChaseItemPos.y));
		break;
	}
}

void SpringAI::Draw() {
	/*DrawFormatString(100, 500, GetColor(255, 255, 0), "item chase pos %f x %f y", onChaseItemPos.x, onChaseItemPos.y);
	DrawFormatString(100, 520, GetColor(255, 255, 0), "player pos %f x %f y", player->Position().x, player->Position().y);
	switch (pAction) {
	case PLAYERACTION::PA_IDLE:
		DrawString(100, 540, "IDLE", GetColor(255, 255, 255));
		break;
	case PLAYERACTION::PA_HOR_MOV_L:
		DrawString(100, 540, "HORIZONTAL MOVE L", GetColor(255, 255, 255));
		break;
	case PLAYERACTION::PA_HOR_MOV_R:
		DrawString(100, 540, "HORIZONTAL MOVE R", GetColor(255, 255, 255));
		break;
	case PLAYERACTION::PA_VER_MOV_U:
		DrawString(100, 540, "VERTICAL MOVE U", GetColor(255, 255, 255));
		break;
	case PLAYERACTION::PA_VER_MOV_D:
		DrawString(100, 540, "VERTICAL MOVE D", GetColor(255, 255, 255));
		break;
	}*/
}