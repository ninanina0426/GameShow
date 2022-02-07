#include "Enemy.h"
#include <DxLib.h>
#include"KeyCheck.h"
#include"GameScene.h"




bool Enemy::init(GameScene* parent)
{
	mParent = parent;

	//parent->Draw();		//ゲームシーンのドローってこと

	mPos.x_ = 0;
	mPos.y_ = 0;

	mMoveSpeed = 2;
	mMoveDir = DIR_DOWN;
	mSize.x_ = 32;
	mSize.y_ = 32;
	mSizeOffset.x_ = mSize.x_ / 2;
	mSizeOffset.y_ = mSize.x_ / 2;

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
	//for (int i = 0; i < 4; i++)
	//{
	//	bulletPos_[i] = { 0,0 };
	//	//BulletFlag_[i] = false;
	//}
	bulletPos_ = { 0,0 };
	BulletFlag_ = false;
	Speed_ = 5;
	for (int i = 0; i < 256; i++)
	{
		BulletID_[i] = LoadGraph("image/shot32.png");
	}
	
	bulletDir_ = DIR::DIR_MAX;
	count_ = 0;

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

Vector2 Enemy::Update(Vector2 player)
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


	plPos_ = player;
	//playerと敵の間の距離

	Vector2 Pos[4];
	Pos[0] = (plPos_ - Vector2{ mPos.x_ - mSizeOffset.x_ + ENEMY_X_1, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_1, });
	Pos[1] = (plPos_ - Vector2{ mPos.x_ - mSizeOffset.x_ + ENEMY_X_2, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_2, });
	Pos[2] = (plPos_ - Vector2{ mPos.x_ - mSizeOffset.x_ + ENEMY_X_3, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_3, });
	Pos[3] = (plPos_ - Vector2{ mPos.x_ - mSizeOffset.x_ + ENEMY_X_4, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_4, });
	/*for (int i = 0; i < 4; i++)
	{
		switch (bulletDir_)
		{
		case DIR_UP:
			bulletPos_[i] -= {0, Speed_};
			break;
		case DIR_RIGHT:
			bulletPos_[i] += {Speed_, 0};
			break;
		case DIR_DOWN:
			bulletPos_[i] += {0, Speed_};
			break;
		case DIR_LEFT:
			bulletPos_[i] -= {Speed_, 0};
			break;
		case DIR_MAX:
			break;
		default:
			break;
		}
	}*/

	switch (bulletDir_)
	{
	case DIR_UP:
		bulletPos_ -= {0, Speed_};
		break;
	case DIR_RIGHT:
		bulletPos_ += {Speed_, 0};
		break;
	case DIR_DOWN:
		bulletPos_ += {0, Speed_};
		break;
	case DIR_LEFT:
		bulletPos_ -= {Speed_, 0};
		break;
	case DIR_MAX:
		break;
	default:
		break;
	}

	for (auto& p : Pos)
	{

		if (!BulletFlag_)
		{
			if (p.x_ >= 0)
			{
				BulletFlag_ = true;
				bulletDir_ = DIR::DIR_RIGHT;
			}
			else
			{
				bulletDir_ = DIR::DIR_LEFT;
				BulletFlag_ = true;
			}


		}
		else
		{
			if ((bulletPos_.x_ < -200 || bulletPos_.x_>200 ||
				bulletPos_.y_ < -200 || bulletPos_.y_>200))
			{
				BulletFlag_ = false;
				bulletPos_ = Vector2{ 0,0 };
			}
		}
	}
	ShotPos = Vector2{  bulletPos_.x_, 0 };

	//金髪
	//if (!BulletFlag_[0])
	//{
	//	if (Pos[0].y_ >= 0)
	//	{
	//		BulletFlag_[0] = true;
	//		bulletDir_ = DIR::DIR_DOWN;
	//	}
	//	else
	//	{
	//		bulletDir_ = DIR::DIR_UP;
	//		BulletFlag_[0] = true;
	//	}
	//}
	//else
	//{
	//	if (bulletPos_[0].y_ < -200 || bulletPos_[0].y_>200)
	//	{
	//		BulletFlag_[0] = false;
	//		bulletPos_[0] = Vector2{ 0,0 };
	//	}
	//}
	////女
	//if (!BulletFlag_[1])
	//{
	//	if (Pos[1].x_ >= 0)
	//	{
	//		BulletFlag_[1] = true;
	//		bulletDir_ = DIR::DIR_RIGHT;
	//	}
	//	else
	//	{
	//		bulletDir_ = DIR::DIR_LEFT;
	//		BulletFlag_[1] = true;
	//	}
	//}
	//else
	//{
	//	if (bulletPos_[1].x_ < -200 || bulletPos_[1].x_>200||
	//		bulletPos_[2].y_ < -200 || bulletPos_[2].y_>200)
	//	{
	//		BulletFlag_[1] = false;
	//		bulletPos_[1] = Vector2{ 0,0 };
	//	}
	//}
	////黒人
	//if (!BulletFlag_[2])
	//{
	//	if (Pos[2].x_ >= 0)
	//	{
	//		BulletFlag_[2] = true;
	//		bulletDir_ = DIR::DIR_RIGHT;
	//	}
	//	else
	//	{
	//		bulletDir_ = DIR::DIR_LEFT;
	//		BulletFlag_[2] = true;
	//	}
	//}
	//else
	//{
	//	if ((bulletPos_[2].x_ < -200 || bulletPos_[2].x_>200 ||
	//		bulletPos_[2].y_ < -200 || bulletPos_[2].y_>200))
	//	{
	//		BulletFlag_[2] = false;
	//		bulletPos_[2] = Vector2{ 0,0 };
	//	}
	//}
	////茶髪
	//if (!BulletFlag_[3])
	//{
	//	if (Pos[2].x_ >= 0)
	//	{
	//		BulletFlag_[3] = true;
	//		bulletDir_ = DIR::DIR_RIGHT;
	//	}
	//	else
	//	{
	//		bulletDir_ = DIR::DIR_LEFT;
	//		BulletFlag_[3] = true;
	//	}
	//}
	//else
	//{
	//	if ((bulletPos_[3].x_ < -200 || bulletPos_[2].x_>200 ||
	//		bulletPos_[3].y_ < -200 || bulletPos_[2].y_>200))
	//	{
	//		BulletFlag_[3] = false;
	//		bulletPos_[3] = Vector2{ 0,0 };
	//	}
	//}

	mAnmCnt++;
	count_++;
	return mPos;
}

void Enemy::Draw(void)
{
	//生きてる---------------------------------
	if (mEnemy1 == true)//金髪
	{
		DrawGraph(mPos.x_ - mSizeOffset.x_ + ENEMY_X_1, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_1, mImage[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mEnemy2 == true)//女
	{
		DrawGraph(mPos.x_ - mSizeOffset.x_ + ENEMY_X_2, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_2, mImage2[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mEnemy3 == true)//黒人
	{
		DrawGraph(mPos.x_ - mSizeOffset.x_ + ENEMY_X_3, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_3, mImage3[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);

	}
	if (mEnemy4 == true)//茶髪
	{
		DrawGraph(mPos.x_ - mSizeOffset.x_ + ENEMY_X_4, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_4, mImage4[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	//死んだ-------------------------------------------------
	if (mPush == true)
	{
		DrawGraph(mPos.x_ - mSizeOffset.x_ + ENEMY_X_1, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_1, mDedImage[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mPush2 == true)
	{
		DrawGraph(mPos.x_ - mSizeOffset.x_ + ENEMY_X_2, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_2, mDedImage2[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mPush3 == true)
	{
		DrawGraph(mPos.x_ - mSizeOffset.x_ + ENEMY_X_3, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_3, mDedImage3[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	if (mPush4 == true)
	{
		DrawGraph(mPos.x_ - mSizeOffset.x_ + ENEMY_X_4, mPos.y_ - mSizeOffset.y_ + ENEMY_Y_4, mDedImage4[mMoveDir * DIR_MAX + ((mAnmCnt / 20) % 4)], true);
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "EnemyPos=(%d,%d)", mPos.x_, mPos.y_);

	DrawGraph((mPos.x_ -mSizeOffset.x_ + ENEMY_X_1) + bulletPos_.x_, (mPos.y_ -mSizeOffset.y_ + ENEMY_Y_1), BulletID_[1], true);
	DrawGraph((mPos.x_ -mSizeOffset.x_ + ENEMY_X_2) + bulletPos_.x_, (mPos.y_ -mSizeOffset.y_ + ENEMY_Y_2), BulletID_[2], true);
	DrawGraph((mPos.x_ -mSizeOffset.x_ + ENEMY_X_3) + bulletPos_.x_, (mPos.y_ -mSizeOffset.y_ + ENEMY_Y_3), BulletID_[3], true);
	DrawGraph((mPos.x_ -mSizeOffset.x_ + ENEMY_X_4) + bulletPos_.x_, (mPos.y_ -mSizeOffset.y_ + ENEMY_Y_4), BulletID_[4], true);

	/*DrawGraph(( - mSizeOffset.x_ + ENEMY_X_1), ( - mSizeOffset.y_ + ENEMY_Y_1) + bulletPos_[0].y_, BulletID_[1], true);
	DrawGraph(( - mSizeOffset.x_ + ENEMY_X_2) + bulletPos_[1].x_, ( - mSizeOffset.y_ + ENEMY_Y_2), BulletID_[2], true);
	DrawGraph(( - mSizeOffset.x_ + ENEMY_X_3) + bulletPos_[2].x_, ( - mSizeOffset.y_ + ENEMY_Y_3), BulletID_[3], true);
	DrawGraph(( - mSizeOffset.x_ + ENEMY_X_4) + bulletPos_[3].x_, ( - mSizeOffset.y_ + ENEMY_Y_4), BulletID_[4], true);*/
	//DrawFormatString(0, 35, 0xffffff, "Bullet=(%d)", );
	DrawFormatString(0, 35, 0xffffff, "Bullet=(%d,%d,%d,%d)", bulletPos_[0], bulletPos_[1], bulletPos_[2], bulletPos_[3]);



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

Vector2 Enemy::GetPos(void)
{
	return mPos;
}

Vector2 Enemy::GetSize(void)
{
	return mSize;
}

Vector2 Enemy::GetShotPos(void)
{
	return ShotPos;
}
