#include "BandouAI.h"

BandouAI::BandouAI()
{
}

BandouAI::~BandouAI()
{
}

void BandouAI::Update()
{
	Set();
	player->Input(target);
}

void BandouAI::Draw()
{
}

void BandouAI::Set()
{
	Vector2 itemPos = V2Get(0, 0);
	float distance = 0;

	for (int i = 0; i < itemmanager->GetItemList().size(); i++) {
		Item* item = (*std::next(itemmanager->GetItemList().begin(), i));

		float distanceX = player->Position().x - item->GetPosition().x;
		float distanceY = player->Position().y - item->GetPosition().y;

		distanceX = max(distanceX, -distanceX);
		distanceY = max(distanceY, -distanceY);

		float currentDis = distanceX + distanceY;

		if (i == 0 || distance > currentDis) {
			distance = currentDis;
			itemPos = item->GetPosition();
		}
	}
	target = itemPos;
}
