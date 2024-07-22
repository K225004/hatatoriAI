#pragma once
#include "../Library/gameObject.h"
#include"PlayerAI.h"

class NarumiAI : public PlayerAI {
public:
	NarumiAI();
	~NarumiAI();
	void Start()override;
	void Update();
	void Draw();
	void SpownObject()override;
private:
	void SearchTarget();
};