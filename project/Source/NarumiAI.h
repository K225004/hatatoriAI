#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"

class NarumiAI : public PlayerAI {
public:
	NarumiAI();
	~NarumiAI();
	void Update();
	void Draw();
private:
	void SearchTarget();
};