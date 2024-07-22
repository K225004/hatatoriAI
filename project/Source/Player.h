#pragma once
#include "../Library/gameObject.h"

namespace {
	static const int SCORE_WEIGHT = 250;
}

class ItemManager;

class Player : public GameObject {
public:
	Player();
	~Player();
	void Start()override;
	void Update() override;
	void Draw() override;
	void SetChara(int id);
	Vector2 Position() {
		return position;
	}
	void Input(Vector2 dir);
	void Input2(Vector2 dir);

	int GetScore() { return score; }
	void SetStop(bool _stop) {
		isStop = _stop;
	}
	void SetVictory(bool _victory) {
		isVictory = _victory;
	}
private:
	Vector2 position;
	const Vector2 SIZE = V2Get(32, 32);
	int hImage;
	int hFont;
	int picY;
	Vector2 input;
	int score;
	int type;
	bool isStop;
	bool isVictory;

	ItemManager* item = nullptr;
	
};