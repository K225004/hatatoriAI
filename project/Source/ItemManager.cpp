#include "ItemManager.h"
#include "Item.h"
#include "config.h"

ItemManager::ItemManager() {

	items.resize(ITEM_MAX);
	for (auto itr = items.begin(); itr != items.end(); itr++) {
		*itr = Instantiate<Item>();
		SpownItem(*itr);
	}

	items.back()->Create(1, V2Get(SCREEN_WIDTH / 2, 0));
}

ItemManager::~ItemManager() {

}

void ItemManager::Update(){
	
}

int ItemManager::DoCollider(const Vector2& pPos, const Vector2& pSize){
	Vector2 iPos;
	Vector2 iSize;
	for (auto itr = items.begin(); itr != items.end(); itr++) {
		iPos = (*itr)->GetPosition();
		iSize= (*itr)->GetSize();
		if (pPos.x < iPos.x + iSize.x && pPos.x + pSize.x>iPos.x && pPos.y<iPos.y + iSize.y && pPos.y + pSize.y>iPos.y) {
			int score = SCORE[(*itr)->GetKind()];
			SpownItem(*itr);
			return score;
		}
	}
	return 0;
}

void ItemManager::SpownItem(Item* item){
	Vector2 position;
	position.x = GetRand(SCREEN_WIDTH);
	position.y = GetRand(SCREEN_HEIGHT);
	item->Create(GetRand(ITEMKIND_MAX - 1), position);
}
