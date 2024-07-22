#include "NarumiAI.h"
#include "ItemManager.h"
#include "Item.h"
#include "bombManager.h"
#include "bomb.h"
#include <math.h>
#include "../ImGui/imgui_impl_dxlib.hpp"

NarumiAI::NarumiAI()
{
}

NarumiAI::~NarumiAI()
{
}

void NarumiAI::Start(){
	PlayerAI::Start();
	SearchTarget();
}

void NarumiAI::Update(){
	Vector2 pCenter = player->Position();
	pCenter.x += 16.0f;
	pCenter.y += 16.0f;

	Vector2 move = V2Get(0, 0);

	float dis = 0;
	float disAbs = 0;



	dis = pCenter.x - target.x;
	disAbs = abs(dis);
	if (disAbs >= 16.0f) {
		if (disAbs > 1) {
			move.x = dis / disAbs * -1;
		}
	}
	

	dis = pCenter.y - target.y;
	disAbs = abs(dis);
	if (disAbs >= 16.0f) {
		if (disAbs > 1) {
			move.y = dis / disAbs * -1;
		}
	}


	if (move.x != 0.0f) {
		move.y = 0.0f;
	}
	player->Input2(move);
}

void NarumiAI::Draw(){
	/*DrawCircle((int)target.x, (int)target.y, 50, 0xffffff, true);
	ImGui::Begin("debugGui");
	ImGui::End();*/
}

void NarumiAI::SpownObject(){
	SearchTarget();
}

void NarumiAI::SearchTarget(){
	std::list<Item*> items = itemmanager->GetItemList();
	
	//‚Æ‚è‚ ‚¦‚¸‹——£‚Æ“¾“_‚ÅŒvŽZ‚·‚é
	float minPoint = 1000.0f;
	float point = 0;
	float distance = 0;
	Vector2 center;
	int score = 0;
	float scoreRate = 0.0f;
	for (auto itr = items.begin(); itr != items.end(); itr++) {
		center = (*itr)->GetPosition() + (*itr)->GetSize() / 2;
		distance = V2Size(player->Position() - center);
		
		score = (*itr)->GetScore();
		//‰¼ˆ—
		if (score == 100) {
			scoreRate = 1.0f;
		}
		else if (score == 300) {
			scoreRate = 0.875f;
		}
		else if (score == 500) {
			scoreRate = 0.75f;
		}
		else if (score == 1000) {
			scoreRate = 0.5f;
		}
		point = distance * scoreRate;
		if (minPoint > point) {
			minPoint = point;
			target = center;
		}
	}
}
