#include <DxLib.h>
#include <memory>
#include "TitleScene.h"
#include "Transition/FadeInOut.h"
#include "GameScene.h"
#include "../_debug/_DebugConOut.h"


TitleScene::TitleScene()
{
	
	Init();
	DrawOwnScn();//黒い画面を出さないようにするためのダミー

}

TitleScene::~TitleScene()
{
}

uniquBaseScn TitleScene::Update( uniquBaseScn own)//もらった所有権が来る
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::make_unique<FadeInOut>(std::move(own), std::make_unique<GameScene>());
	}
	DrawOwnScn();//個別のDraw処理な為必ず書く
	return own;
	//return std::move(own);//自分の所有権をもらった先に返す
}



void TitleScene::DrawOwnScn()
{
	SetDrawScreen(sceneScrID_);
	ClsDrawScreen();
	DrawFormatString(100, 100, 0xffffff, "タイトルが出る予定");
}

bool TitleScene::Init(void)
{
	//lpImageMng.GetID("./image/imageB.png", "imageB.png");
	//TmxObj().LoadTSX("./tmx/map.tsx");
	//Image_ = LoadGraph("image/imageB.png");
	return true;
}


