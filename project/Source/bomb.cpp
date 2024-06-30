#include "bomb.h"

Bomb::Bomb(){
	timer = 0;
	detonetionTime = 0;
	residualTime = 0;
	isExplosion = false;
	blastRange - 0;
	position = V2Get(0, 0);
}

Bomb::~Bomb(){

}

void Bomb::Update(){
	if (isEraseFlg) {
		return;
	}
	timer++;
	if (isExplosion) {
		if (timer >= residualTime) {
			timer = 0;
			isEraseFlg = true;
		}
	}
	else {
		if (timer >= residualTime) {
			timer = 0;
			isExplosion = true;
		}
	}
	
}

void Bomb::Draw(){
	if (isExplosion) {
		//”š•—‚Ì‰æ‘œ‚É·‚µ‘Ö‚¦‚é‚½‚ß‘S•”‰¼ˆ—
		Vector2 beginPos = position;
		Vector2 endPos = position;
		beginPos -= V2Get(blastRange, blastRange);
		endPos += V2Get(blastRange, blastRange);
		DrawBox((int)beginPos.x, (int)beginPos.y, (int)endPos.x, (int)endPos.y, 0xee7800, true);
	}
	else {
		//”š’e‚Ì‰æ‘œ‚É·‚µ‘Ö‚¦‚é‚½‚ß‘S•”‰¼ˆ—
		int radius = 32 / 2;
		DrawCircle((int)position.x, (int)position.y, radius + 1, 0xffffff, false);
	}
}

void Bomb::SetData(const int& _detonetionTime, const int& _residualTime, const int& _blastRange, const Vector2& _position){
	detonetionTime = _detonetionTime;
	residualTime = _residualTime;
	blastRange = _blastRange;
	position = _position;
}


