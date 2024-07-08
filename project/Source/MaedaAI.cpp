#include "MaedaAI.h"

MaedaAI::MaedaAI(){
	score.clear();
	items.clear();
	itemsvalue.clear();
	targetpoint = Point();
	targetpoint.value = 10000.0f;
}

MaedaAI::~MaedaAI(){

}

void MaedaAI::Update(){
	score.clear();
	SetValue();
	for (int i = 0; i < itemsvalue.size(); i++) {
		if ((*std::next(itemsvalue.begin(), i)).value < targetpoint.value) {
			targetpoint = (*std::next(itemsvalue.begin(), i));
		}
	}
	player->Input(targetpoint.pos);
}

void MaedaAI::SetValue(){
	for (int i = 0; i < itemmanager->GetItemList().size(); i++) {
		Item* item = (*std::next(itemmanager->GetItemList().begin(), i));
		itemsvalue.emplace_back();
		itemsvalue.back().pos = Vector2(item->GetPosition().x, item->GetPosition().y);
		itemsvalue.back().abspos = Vector2(player->Position().x - item->GetPosition().x, player->Position().y - item->GetPosition().y);
		if (itemsvalue.back().abspos.x < 0) {
			itemsvalue.back().abspos.x = -itemsvalue.back().pos.x;
		}
		if (itemsvalue.back().abspos.y < 0) {
			itemsvalue.back().abspos.y = -itemsvalue.back().pos.y;
		}
		itemsvalue.back().score = item->GetKind();
		itemsvalue.back().value = (itemsvalue.back().pos.x + itemsvalue.back().pos.y) - (itemsvalue.back().score * 1.5);
	}
}

void MaedaAI::Draw(){
	DrawFormatString(100,300,GetColor(100,100,0),"v2 x %f y %f ",V2Norm(V2Get(1, 2)).x, V2Norm(V2Get(1, 1)).y);
}


