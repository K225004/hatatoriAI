#pragma once
#include "../Library/gameObject.h"

class Bomb;
class PlayerAI;

class BombManager : public GameObject {
public:
	BombManager();
	~BombManager();
	void Update() override;
	void Start()override;
	std::list<Bomb*> GetBombList() { return bombs; }
private:
	int timer;
	int SPOWN_TIME = 60 * 5;//�N�����鎞��
	void SpownBomb();

	std::list<Bomb*> bombs;
	const int DETONETION_TIME = 60 * 5;//�N������
	const int RESIDUAL_TIME = 60 * 2;//�����c������
	const int BLAST_RANGE = 32 * 5 / 2;//�����͈̔�
	
	std::list<PlayerAI*>playerAis;
	bool DoCollider(const Vector2& pPos, const Vector2& pSize);
};