#pragma once
#include "../Library/gameObject.h"

class Bomb : public GameObject {
public:
	Bomb();
	~Bomb();
	void Update() override;
	void Draw()override;

	void SetData(const int& _detonetionTime, const int& _residualTime,const int& _blastRange,const Vector2& _position);

	int GetDetonetionTime()const { return detonetionTime; }
	int GetResidualTime()const { return residualTime; }
	int GetBlastRange()const { return blastRange; }
	Vector2 GetPosition()const { return position; }
	bool GetIsExplosion()const { return isExplosion; }
	bool GetIsEraseFlg()const { return isEraseFlg; }
private:
	int timer;
	int detonetionTime;
	int residualTime;
	bool isExplosion;
	int blastRange;
	Vector2 position;
	bool isEraseFlg;
};