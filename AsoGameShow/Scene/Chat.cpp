#include <DxLib.h>
#include "Chat.h"
#include"KeyCheck.h"


bool Chat::init(void)
{
	mImage[0] = LoadGraph("image/chat/1.png");
	mImage[1] = LoadGraph("image/chat/2.png");
	mImage[2] = LoadGraph("image/chat/3.png");
	mImage[3] = LoadGraph("image/chat/4.png");
	mImage[4] = LoadGraph("image/chat/5.png");
	mImage[5] = LoadGraph("image/chat/6.png");
	mImage[6] = LoadGraph("image/chat/7.png");
	mImage[7] = LoadGraph("image/chat/8.png");
	mImage[8] = LoadGraph("image/chat/9.png");
	mImage[9] = LoadGraph("image/chat/10.png");
	mImage[10] = LoadGraph("image/chat/11.png");
	mImage[11] = LoadGraph("image/chat/12.png");
	mImage[12] = LoadGraph("image/chat/13.png");
	mImage[13] = LoadGraph("image/chat/14.png");
	mImage[14] = LoadGraph("image/chat/15.png");
	mImage[15] = LoadGraph("image/chat/16.png");
	mImage[16] = LoadGraph("image/chat/17.png");

	x = 0;

	mCnt = 0;

	IsEnd = false;
	return true;
}

bool Chat::Update(void)
{
	
	if (CheckHitKey(KEY_INPUT_N))
	{
		mCnt += 2;
	}

	if (mCnt == 1)
	{
		if (x < 18)
		{
			x += 1;
		}

	}
	if (mCnt > 0)
	{
		mCnt--;
	}
	
	if (x == 17)
	{
		IsEnd = true;
	}
	return IsEnd;
}

void Chat::Draw(void)
{
	DrawGraph(0, 0, mImage[x], true);
}

bool Chat::Release(void)
{
	return true;
}
