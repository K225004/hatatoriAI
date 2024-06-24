#pragma once
#include "../Library/gameObject.h"

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
private:
	Vector2 position;
	const Vector2 SIZE = V2Get(32, 32);
	int hImage;
	int picY;
	Vector2 input;
	int score;
	int type;

	ItemManager* item = nullptr;
};