#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"
#include"bombManager.h"
#include"bomb.h"


struct Point{
	/// <summary>
	/// �v���C���[�Ƃ̋����̐�Βl
	/// </summary>
	Vector2 abspos;

	/// <summary>
	/// ���ݒn
	/// </summary>
	Vector2 pos;

	/// <summary>
	/// �A�C�e���̐�Βl
	/// </summary>
	float score;
	/// <summary>
	/// ���l
	/// </summary>
	float value;
	/// <summary>
	/// �A�C�e���ԍ�
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

