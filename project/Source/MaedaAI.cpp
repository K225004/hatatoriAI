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
	SpownObject();
	score.clear();
	for (int i = 0; i < itemsvalue.size(); i++) {
		if (targetpoint.pos.x == player->Position().x && targetpoint.pos.y == player->Position().y) {
			targetpoint = Point();
			targetpoint.value = 10000.0f;
		}
		if ((*std::next(itemsvalue.begin(), i)).value < targetpoint.value) {
			targetpoint = (*std::next(itemsvalue.begin(), i));
		}
		for (auto it : bombManager->GetBombList()) {
			if ((it->GetPosition().x + it->GetBlastRange() > player->Position().x && it->GetPosition().x - it->GetBlastRange() < player->Position().x + 32) && (it->GetPosition().y + it->GetBlastRange() > player->Position().y && it->GetPosition().y - it->GetBlastRange() < player->Position().y + 32)) {
			
			}
		}
	}
	player->Input(targetpoint.pos);
}

void MaedaAI::SpownObject(){
	itemsvalue.clear();
	for (int i = 0; i < itemmanager->GetItemList().size(); i++) {
		Item* item = (*std::next(itemmanager->GetItemList().begin(), i));
		itemsvalue.emplace_back();
		itemsvalue.back().num = i;
		itemsvalue.back().pos = Vector2(item->GetPosition().x, item->GetPosition().y);
		itemsvalue.back().abspos = Vector2(player->Position().x - item->GetPosition().x, player->Position().y - item->GetPosition().y);
		if (itemsvalue.back().abspos.x < 0) {
			itemsvalue.back().abspos.x = -itemsvalue.back().abspos.x;
		}
		if (itemsvalue.back().abspos.y < 0) {
			itemsvalue.back().abspos.y = -itemsvalue.back().abspos.y;
		}
		itemsvalue.back().score = item->GetScore();
		itemsvalue.back().value = ((itemsvalue.back().abspos.x + itemsvalue.back().abspos.y) * 2) - (itemsvalue.back().score * 0.4);
		
		Vector2 playerspos = Vector2(0,0);

		for (auto it : playerlist) {
			playerspos  = Vector2(it->Position().x - item->GetPosition().x, it->Position().y - item->GetPosition().y);
			if (playerspos.x < 0) {
				playerspos.x = -playerspos.x;
			}
			if (playerspos.y < 0) {
				playerspos.y = -playerspos.y;
			}
			float valu = playerspos.x + playerspos.y;
			itemsvalue.back().value -= valu * 0.4;
		}
		itemsvalue.back().value *= 0.001;
	}
}


void MaedaAI::Draw(){
	//DrawFormatString(100,300,GetColor(100,100,0),"v2 x %f y %f ", targetpoint.pos.x, targetpoint.pos.y);
}

void MaedaAI::Start(){
	PlayerAI::Start();
	playerlist = FindGameObjects<Player>();
	playerlist.remove(player);
	SpownObject();
}


