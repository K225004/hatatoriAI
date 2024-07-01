#include "Player.h"
#include "config.h"
#include "ItemManager.h"

Player::Player()
{
	score = 0;
	type = -1;
}

Player::~Player()
{
}

void Player::Start(){
	item = FindGameObject<ItemManager>();
}

void Player::Update()
{
	position += input * 3.0f;
	if (item != nullptr) {
		score += item->DoCollider(position, SIZE);
	}

}

void Player::Draw()
{
	DrawRectGraph(position.x, position.y, 2, 2, SIZE.x, SIZE.y, hImage, true, false);
	char s[32];
	sprintf_s<32>(s, "SCORE %6d", score);
	int x = 0;
	int y = 0;
	switch (type) {
	case 0:
		x = 20;
		y = 20;
		break;
	case 1:
		x = SCREEN_WIDTH-128;
		y = 20;
		break;
	case 2:
		x = 20;
		y = SCREEN_HEIGHT-40;
		break;
	case 3:
		x = SCREEN_WIDTH - 128;
		y = SCREEN_HEIGHT - 40;
		break;
	};
	DrawString(x, y, s, GetColor(255, 255, 255), 0);
}

void Player::SetChara(int id)
{
	type = id;
	switch (id) {
	case 0:
		hImage = LoadGraph("data/textures/player1.png");
		position = V2Get(0, 0);
		break;
	case 1:
		hImage = LoadGraph("data/textures/player2.png");
		position = V2Get(SCREEN_WIDTH - (int)SIZE.x, 0);
		break;
	case 2:
		hImage = LoadGraph("data/textures/player3.png");
		position = V2Get(0, SCREEN_HEIGHT - (int)SIZE.y);
		break;
	case 3:
		hImage = LoadGraph("data/textures/player4.png");
		position = V2Get(SCREEN_WIDTH - (int)SIZE.x, SCREEN_HEIGHT - (int)SIZE.y);
		break;
	}

}

void Player::Input(Vector2 dir)
{
	input = V2Norm(dir);
}
