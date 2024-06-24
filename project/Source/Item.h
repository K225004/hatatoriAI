#pragma once
#include "../Library/gameObject.h"

class Item : public GameObject
{
public:
	Item();
	~Item();
	void Create(int kind, Vector2 pos);
	void Update();
	void Draw();
	Vector2 GetPosition()const { return position; }
	Vector2 GetSize()const { return SIZE; }
	int GetKind()const { return kind; }
private:
	int hImage;
	int kind;
	Vector2 position;
	const Vector2 SIZE = V2Get(32, 32);
};
