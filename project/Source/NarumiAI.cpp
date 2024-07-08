#include "NarumiAI.h"
#include "ItemManager.h"
#include "Item.h"
#include "bombManager.h"
#include "bomb.h"

NarumiAI::NarumiAI()
{
}

NarumiAI::~NarumiAI()
{
}

void NarumiAI::Update()
{
}

void NarumiAI::Draw()
{
}

void NarumiAI::SearchTarget(){
	std::list<Item*> items = itemmanager->GetItemList();
	
	//‚Æ‚è‚ ‚¦‚¸‹——£‚Æ“¾“_‚ÅŒvŽZ‚·‚é
	int minPoint = 1000;
	int point = 0;
	float distance = 0;
	Vector2 center;
	int score = 0;
	float scoreRate = 0.0f;
	for (auto itr = items.begin(); itr != items.end(); itr++) {
		center = (*itr)->GetPosition() + (*itr)->GetSize() / 2;
		distance = V2Size(player->Position() - center);
		
		score = (*itr)->GetScore();
		scoreRate = 1.0f / ((float)score / 100.0f);

		point = distance * scoreRate;
		if (minPoint > point) {
			minPoint = point;
			target = center;
		}
	}
}
