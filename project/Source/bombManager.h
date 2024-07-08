#pragma once
#include "../Library/gameObject.h"

class Bomb;

class BombManager : public GameObject {
public:
	BombManager();
	~BombManager();
	void Update() override;
	std::list<Bomb*> GetBombList() { return bombs; }
private:
	int timer;
	int SPOWN_TIME = 60 * 5;//—N‚©‚¹‚éŽžŠÔ
	void SpownBomb();

	std::list<Bomb*> bombs;
	const int DETONETION_TIME = 60 * 5;//‹N”šŽžŠÔ
	const int RESIDUAL_TIME = 60 * 2;//”š•—Žc—¯ŽžŠÔ
	const int BLAST_RANGE = 32 * 5 / 2;//”š•—‚Ì”ÍˆÍ
	
};