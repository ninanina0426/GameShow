#include <DxLib.h>
#include "EndScene.h"

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
	DrawOwnScn();
	return std::move(own);
}

void EndScene::DrawOwnScn()
{
	SetDrawScreen(sceneScrID_);
	ClsDrawScreen();

	if (endType_ == "end_1")
	{
		DrawFormatString(600, 600, 0xffffff, "END_1 #‚»‚ê‚Í˜ü–‚¾‚ËB");
	}

	if (endType_ == "end_2")
	{
		DrawFormatString(600, 600, 0xffffff, "END_1 #‚»‚ê‚Í˜ü–‚¾‚ËB");
	}
	if (endType_ == "end_3")
	{
		DrawFormatString(600, 600, 0xffffff, "END_1 #‚»‚ê‚Í˜ü–‚¾‚ËB");
	}
}

bool EndScene::Init(void)
{
	return true;
}
