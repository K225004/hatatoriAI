#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"

class MaedaAI:public PlayerAI
{
public:
	MaedaAI();
	~MaedaAI();
	void Update();
	void Draw();

private:
};

