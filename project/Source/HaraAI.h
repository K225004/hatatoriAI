#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"

class HaraAI : public PlayerAI {
public:
	HaraAI();
	~HaraAI();
	void Update();
	void Draw();
private:
	
};