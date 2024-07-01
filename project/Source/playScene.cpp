#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include <DxLib.h>
#include "Player.h"
#include "ItemManager.h"
#include"HaraAI.h"
#include"BandouAI.h"
#include"MaedaAI.h"
#include"NarumiAI.h"
#include"springAI.h"

PlayScene::PlayScene()
{
	Player* inst[5];
	for (int i = 0; i < 5; i++) {
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
