#include "Player.h"
#include <DxLib.h>
#include"KeyCheck.h"
#include"GameScene.h"

bool Player::init(GameScene * parent)
{
	mParent = parent;

	//parent->Draw();		//ゲームシーンのドローってこと

	mPos.X = 531;
	mPos.Y = 230;

	mDorPos.X = 503;
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
	Vector2d copyPos=mPos;

	if (mCnt > 0)
	{
		mPush = true;
	}
	else if (mCnt == 0)
	{
		mPush = false;
	}
	//ドア
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
		//mPos.X += mMoveSpeed / 2;		//プレイヤーのマップ上の移動
		//mPos.Y -= mMoveSpeed / 2;
	}

	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		keyDir = DIR_LEFT;
		/*mPos.X -= mMoveSpeed / 2;
		mPos.Y += mMoveSpeed / 2;
		if (mPos.X < 0)
		{
			mPos.X = 0;
		}*/

	}

	if (CheckHitKey(KEY_INPUT_UP))
	{
		keyDir = DIR_UP;
		/*mPos.Y -= mMoveSpeed / 2;
		if (mPos.Y < 0)
		{
			mPos.Y = 0;
		}*/
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		keyDir = DIR_DOWN;
		/*mPos.Y += mMoveSpeed / 2;*/

	}
	if (CheckHitKey(KEY_INPUT_N))
	{
		mCnt += 10;
	}

	if (mDCnt>0&&mDCnt<55)
	{
		mPos.X -= 1;
		mPos.Y += 1;
	}

	if (keyDir != DIR_MAX)
	{
		mMoveDir = keyDir;

		if (keyDir == DIR_UP)
		{
			copyPos.Y -= mMoveSpeed / 2;
			if (copyPos.Y < 0)
			{
				copyPos.Y = 0;
			}

		}
		if (keyDir == DIR_DOWN)
		{
			copyPos.Y += mMoveSpeed / 2;
			if (copyPos.Y > MAP_Y * CHIP_SIZE_Y)
			{
				copyPos.Y = MAP_Y * CHIP_SIZE_Y;
			}

		}
		if (keyDir == DIR_RIGHT)
		{
			copyPos.X += mMoveSpeed / 2;		//プレイヤーのマップ上の移動
			/*copyPos.Y -= mMoveSpeed / 2;*/
			if (copyPos.X > MAP_X * CHIP_SIZE_X)
			{
				copyPos.X = MAP_X * CHIP_SIZE_X;
			}

		}
		if (keyDir == DIR_LEFT)
		{
			copyPos.X -= mMoveSpeed / 2;
			/*copyPos.Y += mMoveSpeed / 2;*/
			if (copyPos.X < 0)
			{
				copyPos.X = 0;
			}

		}

		//移動範囲を行う
		switch (mParent->GetEvent(copyPos))
		{
		/*case 249:
		case 250:*/
		/*case 267:*/
		/*case 268:*/
		case 269:
		case 270:
		case 271:
		case 273:
		case 285:
		case 286:
		case 287:
		case 288:
		case 289:
		case 290:
		case 291:
		case 292:
		case 293:
		case 294:
		case 303:
		case 304:
		case 305:
		/*case 306:*/
		/*case 307:*/
		case 308:
		case 309:
		case 310:
		case 311:
		case 312:
		/*case 313:*/
		/*case 321:*/
		/*case 322:
		case 323:*/
		case 324:
		/*case 325:*/
		case 326:
		case 327:
		case 328:
		/*case 329:*/
		case 330:
		/*case 331:*/
		/*case 340:*/
		/*case 341:
		case 342:*/
		case 343:
		case 344:
		case 345:
		case 346:
		/*case 347:*/
		/*case 348:*/
		/*case 349:*/
	/*	case 362:*/
		case 363:
		case 364:
		case 365:
		case 366:
		/*case 367:*/
		/*case 384:
		case 385:*/
			mPos = copyPos;
			break;
		default:
			break;
		}

	}

	

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

void Player::Draw(Vector2d offset)
{

	if (mDor == true)
	{
		DrawGraph(mDorPos.X, mDorPos.Y, mImage4[((mAnmCnt / 20) % 4)], true);
	}
	if (mPush == false)
	{
		DrawGraph(mPos.X - offset.X - mSizeOffset.X, mPos.Y - offset.Y - mSizeOffset.Y, mImage[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	else if (mPush == true)
	{
		DrawGraph(mPos.X - offset.X - mSizeOffset.X, mPos.Y - offset.Y - mSizeOffset.Y, mImage2[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
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

void Player::SetPos(Vector2d pos)
{
	mPos = pos;
}


Vector2d Player::GetSiz(void)
{
	return mSize;
}

DIR Player::GetDIR(void)
{
	return mMoveDir;
}
