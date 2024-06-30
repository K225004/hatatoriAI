#include "bombManager.h"
#include "bomb.h"
#include "config.h"

BombManager::BombManager(){
	timer = 0;
}

BombManager::~BombManager(){

}

void BombManager::Update(){
	timer++;
	if (timer >= SPOWN_TIME) {
		timer = 0;
		SpownBomb();
	}

	for (auto itr = bombs.begin(); itr != bombs.end();) {
		if ((*itr)->GetIsEraseFlg()) {
			(*itr)->DestroyMe();
			bombs.erase(itr);
		}
		else {
			itr++;
		}
	}
}

void BombManager::SpownBomb(){
	bombs.emplace_back(Instantiate<Bomb>());
	Vector2 pos = V2Get(GetRandom(SCREEN_WIDTH - 32, 32), GetRandom(SCREEN_HEIGHT - 32, 32));
	bombs.back()->SetData(DETONETION_TIME, RESIDUAL_TIME, BLAST_RANGE, pos);
}


