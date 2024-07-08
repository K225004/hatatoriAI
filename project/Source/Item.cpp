#include "Item.h"
#include "config.h"

Item::Item()
{
	hImage = LoadGraph("data/textures/item.png");
	kind = 0;
	position = V2Get(0, 0);
	score = 0;
}

Item::~Item()
{
}

void Item::Create(const int& _kind, const Vector2& pos, const int& _score){
	kind = _kind;
	position = pos;
	score = _score;
}

void Item::Update()
{
}

void Item::Draw()
{
	DrawRectGraph(position.x, position.y, kind * 36 + 2, 2, SIZE.x, SIZE.y, hImage, true, false);
}
