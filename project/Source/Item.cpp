#include "Item.h"
#include "config.h"

Item::Item()
{
	hImage = LoadGraph("data/textures/item.png");
	kind = 0;
	position = V2Get(0, 0);
}

Item::~Item()
{
}

void Item::Create(int _kind, Vector2 pos){
	kind = _kind;
	position = pos;
}

void Item::Update()
{
}

void Item::Draw()
{
	DrawRectGraph(position.x, position.y, kind * 36 + 2, 2, SIZE.x, SIZE.y, hImage, TRUE);
}
