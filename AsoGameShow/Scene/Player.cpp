#include "Player.h"
#include <DxLib.h>
#include"KeyCheck.h"
#include"GameScene.h"

bool Player::init(GameScene * parent)
{
	mParent = parent;

	//parent->Draw();		//ゲームシーンのドローってこと

	mPos.X = 522;
	mPos.Y = 231;

	mDorPos.X = 493;
	mDorPos.Y = 151;
	

	mMoveSpeed = 2;
	mMoveDir = DIR_LEFT;


	mSize.X = PLAYER_A_SIZE_X;
	mSize.Y = PLAYER_SIZE_Y;
	mSizeOffset.X = mSize.X / 2;
	mSizeOffset.Y = mSize.Y / 2;

	mPush = false;
	mAnmCnt = 0;
	mCnt = 0;
	mDCnt = 75;

	mDor = true;
	SetTransColor(255, 0, 255);

	if (LoadDivGraph("image/03.png", 16, 4, 4, PLAYER_A_SIZE_X, PLAYER_SIZE_Y, &mImage[0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/04.png", 16, 4, 4, PLAYER_A_SIZE_X, PLAYER_SIZE_X, &mImage2[0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/moveDor.png", 4, 4,1, 64, 128, &mImage3[0]) == -1)
	{
		return false;
	}


	if (LoadDivGraph("image/BDor.png", 4, 4, 1, 64, 128, &mImage4[0]) == -1)
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

	if (mDCnt > 0)
	{
		mDor = true;
	}
	else if (mDCnt == 0)
	{
		mDor = false;
		
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

	if (mDCnt > 0)
	{
		mDCnt--;
	}
	
	
	return mPos;
}

void Player::Draw()
{

	if (mDor == true)
	{
		DrawGraph(mDorPos.X, mDorPos.Y, mImage4[((mAnmCnt / 20) % 4)], true);
	}
	if (mPush == false)
	{
		DrawGraph(mPos.X - mSizeOffset.X, mPos.Y - mSizeOffset.Y, mImage[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	else if (mPush == true)
	{
		DrawGraph(mPos.X - mSizeOffset.X, mPos.Y - mSizeOffset.Y, mImage2[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mDor == true)
	{
		DrawGraph(mDorPos.X , mDorPos.Y , mImage3[((mAnmCnt / 20) % 4)], true);
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

bool Player::IsAlive(void)
{
	return false;
}


Vector2d Player::GetSiz(void)
{
	return mSize;
}

DIR Player::GetDIR(void)
{
	return mMoveDir;
}
