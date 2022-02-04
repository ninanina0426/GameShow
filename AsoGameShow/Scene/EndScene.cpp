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
		DrawFormatString(600, 600, 0xffffff, "END_1 #ÇªÇÍÇÕò¸ñùÇæÇÀÅB");
	}
}

bool EndScene::Init(void)
{
	return false;
}
