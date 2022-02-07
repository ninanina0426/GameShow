#include <DxLib.h>
#include "EndScene.h"
#include "Transition/FadeInOut.h"
#include "TitleScene.h"
EndScene::EndScene(std::string endtype)
{
	endType_ = endtype;
	Init();
	DrawOwnScn();
}

EndScene::~EndScene()
{
}

uniquBaseScn EndScene::Update(uniquBaseScn own)
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::make_unique<FadeInOut>(std::move(own), std::make_unique<TitleScene>());
	}
	DrawOwnScn();
	return std::move(own);
}

void EndScene::DrawOwnScn()
{
	SetDrawScreen(sceneScrID_);
	ClsDrawScreen();

	if (endType_ == "end_1")
	{
		DrawFormatString(600, 600, 0xffffff, "END_1 #����͘������ˁB");
	}

	if (endType_ == "end_2")
	{
		DrawFormatString(490, 600, 0xffffff, "END_2 #�D��S�͐g��S�ڂ��񂾂��Ă�");
	}
	if (endType_ == "end_3")
	{
		DrawFormatString(600, 600, 0xffffff, "END_1 #����͘������ˁB");
	}
}

bool EndScene::Init(void)
{
	return true;
}
