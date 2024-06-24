#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include <DxLib.h>
#include "Player.h"
#include "PlayerAI.h"
#include "ItemManager.h"

PlayScene::PlayScene()
{
	Player* inst[4];
	for (int i = 0; i < 4; i++) {
		inst[i] = Instantiate<Player>();
		inst[i]->SetChara(i);
	}
	PlayerAI* ai = Instantiate<PlayerAI>();
	ai->SetPlayer(inst[0]);
	Instantiate<ItemManager>();
}


PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TitleScene");
	}
	SceneBase::Update();
}

void PlayScene::Draw()
{
	SceneBase::Draw();

//	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
//	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
