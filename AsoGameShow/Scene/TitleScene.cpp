#include <DxLib.h>
#include <memory>
#include "TitleScene.h"
#include "Transition/FadeInOut.h"
#include "GameScene.h"
#include "../_debug/_DebugConOut.h"


TitleScene::TitleScene()
{
	
	Init();
	DrawOwnScn();//������ʂ��o���Ȃ��悤�ɂ��邽�߂̃_�~�[

}

TitleScene::~TitleScene()
{
}

uniquBaseScn TitleScene::Update( uniquBaseScn own)//����������L��������
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::make_unique<FadeInOut>(std::move(own), std::make_unique<GameScene>());
	}
	DrawOwnScn();//�ʂ�Draw�����ȈוK������
	return own;
	//return std::move(own);//�����̏��L�������������ɕԂ�
}



void TitleScene::DrawOwnScn()
{
	SetDrawScreen(sceneScrID_);
	ClsDrawScreen();
	DrawFormatString(100, 100, 0xffffff, "�^�C�g�����o��\��");
}

bool TitleScene::Init(void)
{
	//lpImageMng.GetID("./image/imageB.png", "imageB.png");
	//TmxObj().LoadTSX("./tmx/map.tsx");
	//Image_ = LoadGraph("image/imageB.png");
	return true;
}


