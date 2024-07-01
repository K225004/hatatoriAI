#pragma once
#include "../Library/sceneBase.h"
#include"PlayerAI.h"

class PlayScene : public SceneBase {
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
private:
	std::list<PlayerAI*> ai;
};