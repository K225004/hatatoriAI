#include "Player.h"
#include "config.h"
#include "ItemManager.h"

Player::Player()
{
	hFont = -1;
	score = 0;
	type = -1;
	isStop = false;
	isVictory = false;
}

Player::~Player()
{
	DeleteFontToHandle(hFont);
}

void Player::Start(){
	item = FindGameObject<ItemManager>();
}

void Player::Update()
{
	//position += input * 3.0f;
	if (item != nullptr) {
		score += item->DoCollider(position, SIZE);
	}

}

void Player::Draw()
{
	DrawRectGraph(position.x, position.y, 2, 2, SIZE.x, SIZE.y, hImage, true, false);
	char s[32];
	sprintf_s<32>(s, "player%d SCORE %6d", type + 1, score);
	int x = 20 + (type * SCORE_WEIGHT);
	int y = 20;

	DrawString(x, y, s, GetColor(255, 255, 255), 0);

	
	if (isVictory) {
		//hFont = CreateFontToHandle(NULL, 64, 3);
		DrawFormatString(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0xffffff, "player%d WIN!! ", type + 1);
		//DrawFormatStringToHandle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0xffffff, hFont, "player%d WIN!! ", type + 1);
	}
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
	default:
		hImage = LoadGraph("data/textures/player5.png");
		position = V2Get((SCREEN_WIDTH / 2) - (int)SIZE.x, (SCREEN_HEIGHT / 2) - (int)SIZE.y);
		break;
	}
}

void Player::Input(Vector2 dir)
{
	//input = V2Norm(dir);
	if (!isStop) {
		if (dir.x > position.x) {
			position.x++;
		}
		else if (dir.x < position.x) {
			position.x--;
		}
		else if (dir.y > position.y) {
			position.y++;
		}
		else if (dir.y < position.y) {
			position.y--;
		}
	}
}

void Player::Input2(Vector2 dir) {
	if (!isStop) {
		float direction = atan2f(dir.x, dir.y);
		MATRIX mrot = MGetRotY(direction);
		VECTOR move = VGet(0, 0, 1.0f);
		move *= mrot;

		position.x += move.x;
		position.y += move.z;
	}
}
