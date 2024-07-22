#pragma once
#include "../Library/gameObject.h"

class Item;
class PlayerAI;

class ItemManager : public GameObject {
public:
	ItemManager();
	~ItemManager();
	void Start()override;
	void Update() override;

	int DoCollider(const Vector2& pPos, const Vector2& pSize);
	std::list<Item*> GetItemList() { return items; }
private:
	const int ITEM_MAX = 10;
	std::list<Item*> items;

	void SpownItem(Item* item);

	static const int ITEMKIND_MAX = 4;

	const int SCORE[ITEMKIND_MAX] = { 100,300,500,1000 };

	std::list<PlayerAI*>playerAis;

	Vector2 itemSize;
};