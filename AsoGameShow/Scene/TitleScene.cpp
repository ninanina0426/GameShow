#include <DxLib.h>
#include <memory>
#include "SceneMng.h"
#include "TitleScene.h"
#include "Transition/FadeInOut.h"
#include "PrologueScene.h"
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
		return std::make_unique<FadeInOut>(std::move(own), std::make_unique<PrologueScene>());
	}
	DrawOwnScn();//個別のDraw処理な為必ず書く
	count++;
	return std::move(own);
	
}



void TitleScene::DrawOwnScn()
{
	SetDrawScreen(sceneScrID_);
	ClsDrawScreen();
	
	DrawBox(0, 0, 800, 650, 0xffffff, true);
	//if (count <= 150)
	//{
	//	auto alpha = static_cast<int>(255.0 * count / 70);
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	//	//下の値を変える
	//	DrawGraph(100, 300 - count, Image_, true);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);
	//}
	//else 
	//{
	//	
	//}
	DrawGraph(80, 50, Image_, true);

	DrawFormatString(375, 620, 0x000000, "push space");
}

bool TitleScene::Init(void)
{
	
	count = 0;
	Image_ = LoadGraph("image/title.png");
	return true;
}


