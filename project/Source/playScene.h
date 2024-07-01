#pragma once
#include "../Library/sceneBase.h"
#include"PlayerAI.h"

namespace PLAYER {
	static const int MAX = 5;
}

class PlayScene : public SceneBase {
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
private:
	std::list<PlayerAI*> ai;
};