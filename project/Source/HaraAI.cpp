#include "HaraAI.h"

HaraAI::HaraAI()
{
	distance = 0.0f;
}

HaraAI::~HaraAI()
{
}

void HaraAI::Update()
{
	Set();	
	player->Input(target);
}

void HaraAI::Draw()
{
	//DrawFormatString(10, 200, 0xffffff, "%.2f", distance);
}

void HaraAI::Set()
{
	Vector2 itemPos = V2Get(0, 0);
	distance = 0.0f;

	for (int i = 0; i < itemmanager->GetItemList().size(); i++) {
		Item* item = (*std::next(itemmanager->GetItemList().begin(), i));

		//‹——£
		float distanceX = player->Position().x - item->GetPosition().x;
		float distanceY = player->Position().y - item->GetPosition().y;

		//â‘Î’lŒvŽZ
		distanceX = max(distanceX, -distanceX);
		distanceY = max(distanceY, -distanceY);

		//”{—¦
		float magnification = item->GetKind() * MAGNIFICATION;

		//‘‡
		float nowDistance = distanceX + distanceY - magnification;

		//”»’è
		if (i == 0 || distance > nowDistance) {
			distance = nowDistance;
			itemPos = item->GetPosition();
		}		
	}

	target = itemPos;
}
