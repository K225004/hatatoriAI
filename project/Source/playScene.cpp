#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include <DxLib.h>
#include "Player.h"
#include "ItemManager.h"
#include "bombManager.h"
#include"HaraAI.h"
#include"BandouAI.h"
#include"MaedaAI.h"
#include"NarumiAI.h"
#include"springAI.h"

PlayScene::PlayScene()
{
	for (int i = 0; i < PLAYER::MAX; i++) {
		inst[i] = Instantiate<Player>();
		inst[i]->SetChara(i);
	}
	ai.emplace_back(Instantiate<HaraAI>());
	ai.emplace_back(Instantiate<SpringAI>());
	ai.emplace_back(Instantiate<BandouAI>());
	ai.emplace_back(Instantiate<NarumiAI>());
	ai.emplace_back(Instantiate<MaedaAI>());

	int i = 0;
	for (auto it : ai) {
		it->SetPlayer(inst[i]);
		i++;
	}
	
	Instantiate<ItemManager>();
	Instantiate<BombManager>();

	isFinish = false;
}


PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TitleScene");
	}

	for (int i = 0; i < PLAYER::MAX; i++) {
		if (inst[i]->GetScore() >= 5000) {
			inst[i]->SetVictory(true);
			isFinish = true;
		}
		if (isFinish) {
			inst[i]->SetStop(true);
		}
	}

	SceneBase::Update();
}

void PlayScene::Draw()
{

	SceneBase::Draw();

//	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
//	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
