#include "bombManager.h"
#include "bomb.h"
#include "config.h"
#include "PlayerAI.h"

BombManager::BombManager(){
	timer = 0;
}

BombManager::~BombManager(){

}

void BombManager::Update(){
	return;
	timer++;
	if (timer >= SPOWN_TIME) {
		timer = 0;
		SpownBomb();
	}

	for (auto itr = bombs.begin(); itr != bombs.end();) {
		if ((*itr)->GetIsEraseFlg()) {
			(*itr)->DestroyMe();
			bombs.erase(itr);
			if ((int)bombs.size() < 1) {
				break;
			}
		}
		else {
			itr++;
		}
	}
}

void BombManager::Start(){
	playerAis = FindGameObjects<PlayerAI>();
}

void BombManager::SpownBomb(){
	bombs.emplace_back(Instantiate<Bomb>());
	Vector2 pos = V2Get(GetRandom(SCREEN_WIDTH - 32, 32), GetRandom(SCREEN_HEIGHT - 32, 32));
	bombs.back()->SetData(DETONETION_TIME, RESIDUAL_TIME, BLAST_RANGE, pos);
	for (auto itr = playerAis.begin(); itr != playerAis.end(); itr++) {
		(*itr)->SpownObject();
	}
}

bool BombManager::DoCollider(const Vector2& pPos, const Vector2& pSize){
	Vector2 bPos;
	float blastRange;
	for (auto itr = bombs.begin(); itr != bombs.end(); itr++) {
		if (!(*itr)->GetIsExplosion()) {
			continue;
		}
		bPos = (*itr)->GetPosition();
		blastRange = (*itr)->GetBlastRange();
		if (pPos.x < bPos.x + 32 + blastRange && pPos.x + pSize.x>bPos.x - blastRange &&
			pPos.y<bPos.y + 32 + blastRange && pPos.y + pSize.y>bPos.y - blastRange) {
			return true;
		}
	}
	return false;
}


