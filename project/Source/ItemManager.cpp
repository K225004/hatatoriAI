#include "ItemManager.h"
#include "Item.h"
#include "config.h"
#include "PlayerAI.h"

ItemManager::ItemManager() {

	items.resize(ITEM_MAX);
	for (auto itr = items.begin(); itr != items.end(); itr++) {
		*itr = Instantiate<Item>();
		SpownItem(*itr);
	}
	itemSize = items.back()->GetSize();
}

ItemManager::~ItemManager() {

}

void ItemManager::Start(){
	playerAis = FindGameObjects<PlayerAI>();
}

void ItemManager::Update(){
	
}

int ItemManager::DoCollider(const Vector2& pPos, const Vector2& pSize){
	Vector2 iPos;
	for (auto itr = items.begin(); itr != items.end(); itr++) {
		iPos = (*itr)->GetPosition();
		if (pPos.x < iPos.x + itemSize.x && pPos.x + pSize.x>iPos.x && pPos.y<iPos.y + itemSize.y && pPos.y + pSize.y>iPos.y) {
			int score = SCORE[(*itr)->GetKind()];
			SpownItem(*itr);
			return score;
		}
	}
	return 0;
}

void ItemManager::SpownItem(Item* item){
	Vector2 position;
	int X = SCREEN_WIDTH - (int)itemSize.x;
	int Y = SCREEN_HEIGHT - (int)itemSize.y;
	position.x = (float)GetRand(X);
	position.y = (float)GetRand(Y);
	int kind = GetRand(ITEMKIND_MAX - 1);
	item->Create(kind, position, SCORE[kind]);
	for (auto itr = playerAis.begin(); itr != playerAis.end(); itr++) {
		(*itr)->SpownObject();
	}
}
