#include "Player.h"
#include <DxLib.h>
#include"KeyCheck.h"
#include"GameScene.h"

bool Player::init(GameScene * parent)
{
	mParent = parent;

	//parent->Draw();		//ゲームシーンのドローってこと

	mPos.X = 500;
	mPos.Y = 276;

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

	if (LoadDivGraph("image/01.png", 16, 4, 4, PLAYER_SIZE_X, PLAYER_SIZE_Y, &mImage[0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/02.png", 16, 4, 4, PLAYER_SIZE_X, PLAYER_SIZE_Y, &mImage2[0]) == -1)
	{
		return false;
	}
	return true;

}

Vector2d Player::Update(void)
{
	DIR keyDir = DIR_MAX;		//キー入力の方向

	if (mCnt > 0)
	{
		mPush = true;
	}
	else if (mCnt == 0)
	{
		mPush = false;
	}

	//プレイヤーの操作
	//攻撃
	
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		keyDir = DIR_RIGHT;
		mPos.X += mMoveSpeed / 2;		//プレイヤーのマップ上の移動
		mPos.Y -= mMoveSpeed / 2;
	}

	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		keyDir = DIR_LEFT;
		mPos.X -= mMoveSpeed / 2;
		mPos.Y += mMoveSpeed / 2;
		if (mPos.X < 0)
		{
			mPos.X = 0;
		}

	}

	if (CheckHitKey(KEY_INPUT_UP))
	{
		keyDir = DIR_UP;
		mPos.Y -= mMoveSpeed / 2;
		if (mPos.Y < 0)
		{
			mPos.Y = 0;
		}
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		keyDir = DIR_DOWN;
		mPos.Y += mMoveSpeed / 2;

	}

	
	if (CheckHitKey(KEY_INPUT_N))
	{
		mCnt += 10;
	}

	if (keyDir != DIR_MAX)
	{
		mMoveDir = keyDir;
	}
	//

	//if (keyDir != DIR_MAX)
	//{
	//	mMoveDir = keyDir;


	//	//プレイヤー

	//	

	//	if (keyDir == DIR_UP)
	//	{
	//		mPos.Y -= mMoveSpeed / 2;
	//		if (mPos.Y < 0)
	//		{
	//			mPos.Y = 0;
	//		}

	//	}
	//	if (keyDir == DIR_DOWN)
	//	{
	//		mPos.Y += mMoveSpeed / 2;

	//	}
	//	if (keyDir == DIR_RIGHT)
	//	{
	//		mPos.X += mMoveSpeed / 2;		//プレイヤーのマップ上の移動
	//		mPos.Y -= mMoveSpeed / 2;


	//	}
	//	if (keyDir == DIR_LEFT)
	//	{
	//		mPos.X -= mMoveSpeed / 2;
	//		mPos.Y += mMoveSpeed / 2;
	//		if (mPos.X < 0)
	//		{
	//			mPos.X = 0;
	//		}

	//	}

	//}



	mAnmCnt++;
	
	if (mCnt > 0)
	{
		mCnt--;
	}
	
	
	return mPos;
}

void Player::Draw()
{
	if (mPush == false)
	{
		DrawGraph(mPos.X - mSizeOffset.X, mPos.Y - mSizeOffset.Y, mImage[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	else if (mPush == true)
	{
		DrawGraph(mPos.X - mSizeOffset.X, mPos.Y - mSizeOffset.Y, mImage2[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	DrawFormatString(0, 50, GetColor(255, 255, 255), "playerPos=(%d,%d)", mPos.X, mPos.Y);

}

bool Player::Release(void)
{
	for (int i = 0; i < 16; i++)
	{
		DeleteGraph(mImage[i]);
		DeleteGraph(mImage2[i]);
	}
	return true;
}

DIR Player::GetDIR(void)
{
	return mMoveDir;
}
