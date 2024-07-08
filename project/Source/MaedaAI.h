#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"


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
	Point() {
		abspos = Vector2(0, 0);
		pos = Vector2(0, 0);
		score = 0;
		value = 0;
	}
};

class MaedaAI:public PlayerAI
{
public:
	MaedaAI();
	~MaedaAI();
	void Update();
	void Draw();

private:

	void SetValue();

	Point targetpoint;

	std::list<float> score;
	std::list<Item*> items;
	std::list<Point> itemsvalue;
};

