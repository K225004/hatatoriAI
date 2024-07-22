#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"
#include"bombManager.h"
#include"bomb.h"


struct Point{
	/// <summary>
	/// プレイヤーとの距離の絶対値
	/// </summary>
	Vector2 abspos;

	/// <summary>
	/// 現在地
	/// </summary>
	Vector2 pos;

	/// <summary>
	/// アイテムの絶対値
	/// </summary>
	float score;
	/// <summary>
	/// 価値
	/// </summary>
	float value;
	/// <summary>
	/// アイテム番号
	/// </summary>
	int num;
	Point() {
		abspos = Vector2(0, 0);
		pos = Vector2(0, 0);
		score = 0;
		value = 0;
		num = 0;
	}
};

class MaedaAI:public PlayerAI
{
public:
	MaedaAI();
	~MaedaAI();
	void Update();
	void Draw();

	void Start()override;

	void SpownObject()override;

private:

	Point targetpoint;

	std::list<float> score;
	std::list<Item*> items;
	std::list<Point> itemsvalue;
	std::list<Player*> playerlist;
};

