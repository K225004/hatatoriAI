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
	//�m�F�p
	//DrawFormatString(10, 200, 0xffffff, "%.2f", distance);
	//DrawCircle(player->Position().x, player->Position().y, SEARCH_NEAR, 0xff0000, false);
	//DrawCircle(target.x, target.y, 32, 0xff0000, true, true);
}

void HaraAI::Set()
{
	Vector2 itemPos = V2Get(0, 0);
	distance = 0.0f;

	for (int i = 0; i < itemmanager->GetItemList().size(); i++) {
		Item* item = (*std::next(itemmanager->GetItemList().begin(), i));

		//����
		float distanceX = player->Position().x - item->GetPosition().x;
		float distanceY = player->Position().y - item->GetPosition().y;

		//��Βl�v�Z
		distanceX = max(distanceX, -distanceX);
		distanceY = max(distanceY, -distanceY);

		//����
		float nowDistance = distanceX + distanceY;

		//����
		//�_����������
		if (item->GetKind() >= 500) {
			if (distance > nowDistance) {
				distance = nowDistance;
				itemPos = item->GetPosition();
			}
		}		
		//�������߂���
		else if (distance == 0.0f || (nowDistance < distance && nowDistance <= SEARCH_NEAR)) {
			distance = nowDistance;
			itemPos = item->GetPosition();			
		}	
	}

	target = itemPos;
}
