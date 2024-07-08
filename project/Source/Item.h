#pragma once
#include "../Library/gameObject.h"

class Item : public GameObject
{
public:
	Item();
	~Item();
	void Create(const int& kind, const Vector2& pos,const int& _score);
	void Update();
	void Draw();
	Vector2 GetPosition()const { return position; }
	Vector2 GetSize()const { return SIZE; }
	int GetKind()const { return kind; }
	int GetScore()const { return score; }
private:
	int hImage;
	int kind;
	Vector2 position;
	const Vector2 SIZE = V2Get(32, 32);
	int score;
};
