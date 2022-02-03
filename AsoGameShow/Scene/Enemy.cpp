#include "Enemy.h"
#include <DxLib.h>
#include"KeyCheck.h"
#include"GameScene.h"


bool Enemy::init(GameScene* parent)
{
	mParent = parent;

	//parent->Draw();		//ゲームシーンのドローってこと

	mPos.X = 0;
	mPos.Y = 0;

	mMoveSpeed = 2;
	mMoveDir = DIR_DOWN;
	mSize.X = 32;
	mSize.Y = 32;
	mSizeOffset.X = mSize.X / 2;
	mSizeOffset.Y = mSize.Y / 2;


	mPush = false;
	mAnmCnt = 0;
	mCnt = 0;
	SetTransColor(255, 0, 255);

	if (LoadDivGraph("image/11.png", 16, 4, 4, PLAYER_SIZE_X, PLAYER_SIZE_Y, &mImage[0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/12.png", 16, 4, 4, PLAYER_SIZE_X, PLAYER_SIZE_Y, &mImage2[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/13.png", 16, 4, 4, PLAYER_SIZE_X, PLAYER_SIZE_Y, &mImage3[0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/14.png", 16, 4, 4, PLAYER_SIZE_X, PLAYER_SIZE_Y, &mImage4[0]) == -1)
	{
		return false;
	}
	return true;
}

Vector2d Enemy::Update(void)
{

	mAnmCnt++;
	return mPos;
}

void Enemy::Draw(void)
{
	DrawGraph(mPos.X - mSizeOffset.X+495 , mPos.Y - mSizeOffset.Y+221, mImage[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	DrawGraph(mPos.X - mSizeOffset.X+437, mPos.Y - mSizeOffset.Y+297, mImage2[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	DrawGraph(mPos.X - mSizeOffset.X+310, mPos.Y - mSizeOffset.Y+317, mImage3[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	DrawGraph(mPos.X - mSizeOffset.X+334, mPos.Y - mSizeOffset.Y+403, mImage4[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);

}

bool Enemy::Release(void)
{
	for (int i = 0; i < 16; i++)
	{
		DeleteGraph(mImage[i]);
		DeleteGraph(mImage2[i]);
		DeleteGraph(mImage3[i]);
		DeleteGraph(mImage4[i]);
	}
	return true;
}

DIR Enemy::GetDIR(void)
{
	return mMoveDir;
}
