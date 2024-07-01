#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"

class BandouAI : public PlayerAI {
public:
	BandouAI();
	~BandouAI();
	void Update();
	void Draw();
private:
	
};