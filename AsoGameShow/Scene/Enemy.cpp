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

	mEnemy1 = true;
	mEnemy2 = true;
	mEnemy3 = true;
	mEnemy4 = true;

	mPush = false;
	mPush2 = false;
	mPush3 = false;
	mPush4 = false;
	mAnmCnt = 0;
	mCnt = 0;
	SetTransColor(255, 0, 255);

	//true-------------------------------------------------
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
	//false-------------------------------------------------
	if (LoadDivGraph("image/ded1.png", 16, 4, 4, PLAYER_SIZE_X, PLAYER_SIZE_Y, &mDedImage[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/ded2.png", 16, 4, 4, PLAYER_SIZE_X, PLAYER_SIZE_Y, &mDedImage2[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/ded2.png", 16, 4, 4, PLAYER_SIZE_X, PLAYER_SIZE_Y, &mDedImage3[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/ded1.png", 16, 4, 4, PLAYER_SIZE_X, PLAYER_SIZE_Y, &mDedImage4[0]) == -1)
	{
		return false;
	}
	return true;
}

Vector2d Enemy::Update(void)
{
	//-----------------------
	if (mCnt > 0)
	{
		mPush = true;
	}
	else if (mCnt == 0)
	{
		mPush = false;
	}
	if (mCnt > 0)
	{
		mCnt--;
	}
	//-----------------------
	if (mCnt2 > 0)
	{
		mPush2 = true;
	}
	else if (mCnt2 == 0)
	{
		mPush2 = false;
	}
	if (mCnt2 > 0)
	{
		mCnt2--;
	}
	//-----------------------
	if (mCnt3 > 0)
	{
		mPush3 = true;
	}
	else if (mCnt3 == 0)
	{
		mPush3 = false;
	}
	if (mCnt3 > 0)
	{
		mCnt3--;
	}
	//-----------------------
	if (mCnt4 > 0)
	{
		mPush4 = true;
	}
	else if (mCnt4 == 0)
	{
		mPush4 = false;
	}
	if (mCnt4 > 0)
	{
		mCnt4--;
	}

	mAnmCnt++;
	return mPos;
}

void Enemy::Draw(void)
{
	//生きてる---------------------------------
	if (mEnemy1 == true)//金髪
	{
		DrawGraph(mPos.X - mSizeOffset.X + ENEMY_X_1, mPos.Y - mSizeOffset.Y + ENEMY_Y_1, mImage[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mEnemy2 == true)//女
	{
		DrawGraph(mPos.X - mSizeOffset.X + ENEMY_X_2, mPos.Y - mSizeOffset.Y + ENEMY_Y_2, mImage2[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mEnemy3 == true)//黒人
	{
		DrawGraph(mPos.X - mSizeOffset.X + ENEMY_X_3, mPos.Y - mSizeOffset.Y + ENEMY_Y_3, mImage3[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);

	}
	if (mEnemy4 == true)//茶髪
	{
		DrawGraph(mPos.X - mSizeOffset.X + ENEMY_X_4, mPos.Y - mSizeOffset.Y + ENEMY_Y_4, mImage4[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	//死んだ-------------------------------------------------
	if (mPush==true)
	{
		DrawGraph(mPos.X - mSizeOffset.X + ENEMY_X_1, mPos.Y - mSizeOffset.Y + ENEMY_Y_1, mDedImage[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mPush2 == true)
	{
		DrawGraph(mPos.X - mSizeOffset.X + ENEMY_X_2, mPos.Y - mSizeOffset.Y + ENEMY_Y_2, mDedImage2[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mPush3 == true)
	{
		DrawGraph(mPos.X - mSizeOffset.X + ENEMY_X_3, mPos.Y - mSizeOffset.Y + ENEMY_Y_3, mDedImage3[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mPush4 == true)
	{
		DrawGraph(mPos.X - mSizeOffset.X + ENEMY_X_4, mPos.Y - mSizeOffset.Y + ENEMY_Y_4, mDedImage4[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}


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

bool Enemy::IsAlive(void)
{
	return false;
}

Vector2d Enemy::GetPos(void)
{
	return mPos;
}

Vector2d Enemy::GetSize(void)
{
	return mSize;
}
