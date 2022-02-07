#include <DxLib.h>
#include "PrologueScene.h"
#include "Transition/CrossOver.h"
#include "Transition/FadeInOut.h"
#include "EndScene.h"
#include "GameScene.h"


PrologueScene::PrologueScene()
{
	Init();
	DrawOwnScn();
}

PrologueScene::~PrologueScene()
{
}

uniquBaseScn PrologueScene::Update(uniquBaseScn own)
{
	if (name_=="normal")
	{
		return std::make_unique<FadeInOut>(std::move(own), std::make_unique<GameScene>());
	}
	else if(name_=="end_1")
	{
		return std::make_unique<CrossOver>(std::move(own), std::make_unique<EndScene>(name_));
	}
	if (CheckHitKey(KEY_INPUT_N))
	{
		return std::make_unique<CrossOver>(std::move(own), std::make_unique<GameScene>());
	}
	DrawOwnScn();//å¬ï ÇÃDrawèàóùÇ»à◊ïKÇ∏èëÇ≠
	count++;
	return std::move(own);
}

void PrologueScene::DrawOwnScn()
{
	SetDrawScreen(sceneScrID_);
	ClsDrawScreen();

	if (Prologue())
	{
		ChatDrow("1");
	}
	DrawFormatString(720, 630, 0xffffff, "skip N");
	
}

bool PrologueScene::Init(void)
{
	pos_ = { 500, 550 };
	Downsize_ = { 0,120 };
	count = 0;
	name_ = "non";
	Flag_ = false;
	cuntspeed_ = 0;
	chatBox_ = LoadGraph("image/chatbox.png");
	
	/*icon_[0];
	icon_[1];*/
	return false;
}

void PrologueScene::ChatDrow(std::string name)
{
	DrawBox(10, -10, 790, 700, 0xffffff, false);
	cuntspeed_ = count / 150;
	if (cuntspeed_ >= 1)
	{
		DrawFormatString(350, 5, 0xffffff, "XXXX/Å¢Å¢/ÅõÅõ");
		DrawGraph(120, 20, chatBox_, true);
		DrawFormatString(160, 50, 0xffffff, "Hello! I'm Jake.\nI want you to get rid the rumored ghostslately!!\nPlease!");
	}
	if (cuntspeed_ >= 2)
	{
		DrawGraph(120, 20+Downsize_.y_, chatBox_, true);
		DrawFormatString(160, 50+Downsize_.y_, 0xffffff, "Well,the address is\nA corporation,12583,433,Ave,New York,NY 170384");
	}
	Vector2 boxpos_ = { 500, 550 };
	Vector2 boxsize_ = { 100,30 };
	
	if (Flag_ && pos_.x_ == boxpos_.x_)
	{
		DrawExtendGraph(300, 20 + (Downsize_.y_ * 2), 700, 20 + (Downsize_.y_ * 2) + 100, chatBox_, true);
		DrawFormatString(330, 60 + (Downsize_.y_ * 2), 0xffffff, "All right,leave it to me.");
		cuntspeed_ = 300;
		if (cuntspeed_ > 4)
		{
			DrawGraph(120, 20 + (Downsize_.y_ * 3), chatBox_, true);
			DrawFormatString(160, 50 + (Downsize_.y_ * 3), 0xffffff, "Thank you! Good luck!!");
			
		}
		if (cuntspeed_>=5)
		{
			name_ = "normal";
		}
	}
	else if (Flag_ && pos_.x_ == boxpos_.x_ + 150)
	{
		DrawExtendGraph(300, 20 + (Downsize_.y_ * 2), 700, 20 + (Downsize_.y_ * 2) + 100, chatBox_, true);
		DrawFormatString(330, 60 + (Downsize_.y_ * 2), 0xffffff, "Sorry.I can't.");
		DrawGraph(120, 20 + (Downsize_.y_ * 3), chatBox_, true);
		DrawFormatString(160, 50 + (Downsize_.y_ * 3), 0xffffff, "Hum?? Ok.");
		name_ = "end_1";
	}

	if (cuntspeed_ >= 3&&Flag_==false)
	{
		DrawBox(boxpos_.x_, boxpos_.y_, boxpos_.x_ + boxsize_.x_, boxpos_.y_ + boxsize_.y_, 0xaa0000, true);
		DrawBox(boxpos_.x_+150, boxpos_.y_, boxpos_.x_ + boxsize_.x_+150, boxpos_.y_ + boxsize_.y_, 0x0000aa, true);
		DrawFormatString(boxpos_.x_, boxpos_.y_ - 30,0xffffff,"Which?");
		DrawFormatString(boxpos_.x_+20, boxpos_.y_+8, 0xffffff, "Yes.");
		DrawFormatString(boxpos_.x_+170, boxpos_.y_+8, 0xffffff, "No.");

		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			pos_ = { boxpos_.x_, boxpos_.y_ };
		}
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			pos_ = { boxpos_.x_ + 150, boxpos_.y_ };
		}

		if (CheckHitKey(KEY_INPUT_SPACE) && pos_.x_ == boxpos_.x_)
		{
			cuntspeed_ = 300;
			Flag_ = true;
		}
		if (CheckHitKey(KEY_INPUT_SPACE) && pos_.x_ == boxpos_.x_+150)
		{
			cuntspeed_ = 300;
			Flag_ = true;
		}
		DrawBox(pos_.x_, pos_.y_, pos_.x_ + boxsize_.x_, pos_.y_ + boxsize_.y_, 0xffffff, false);
	}


	
	
	
}

bool PrologueScene::Prologue(void)
{
	auto alpha = static_cast<int>(255.0 * count / 180);
	if (alpha >= 255)
	{
		return true;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - alpha);
	DrawBox(0, 0, 800, 650, 0x000000, true);
	DrawFormatString(380, 300, 0xffffff, "Å\One dayÅ\");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);

	return false;
}
