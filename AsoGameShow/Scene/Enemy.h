#pragma once
#include "common/Vector2.h"
#include "GameCommon.h"
class GameScene;



class Enemy
{
private:

	GameScene* mParent;

	int mImage[16];		//画像の格納領域
	int mImage2[16];		//画像の格納領域
	int mImage3[16];		//画像の格納領域
	int mImage4[16];		//画像の格納領域

	int mDedImage[16];		//画像の格納領域
	int mDedImage2[16];		//画像の格納領域
	int mDedImage3[16];		//画像の格納領域
	int mDedImage4[16];		//画像の格納領域

	
	
	int mLife;			//キャラクターの体力
	int mLifeMax;		//キャラクターの最大体力値

	DIR mMoveDir;		//キャラクターの向き
	Vector2 mPos;		//キャラクターの地図上の座標
	Vector2 mSizeOffset;//キャラクターのオフセットサイズ　　半分の値
	Vector2 mSize;		//キャラクター画像のサイズ
	int mMoveSpeed;		//キャラクター移動スピード
	int mAnmCnt;		//キャラクターのアニメーション

	Vector2 plPos_;


	//弾関連（クラス作ってもいいけどちょっとめんどう？）
	//Vector2 bulletPos_[4];
	Vector2 bulletPos_;

	int Speed_;
	int BulletID_[256];
	int count_;
	//bool BulletFlag_[4];
	bool BulletFlag_;

	DIR bulletDir_;
	Vector2 ShotPos;
public:
	int mPosBottom;	//キャラクターの足元のY座標

	bool init(GameScene* parent);		//初期化
	Vector2 Update(Vector2 player);		//更新
	void Draw(void);		//描画
	bool Release(void);		//開放
	DIR GetDIR(void);
	bool IsAlive(void);
//<<<<<<< HEAD
//	Vector2d GetPos(void);
//	Vector2d GetSize(void);
//
	void IsDestry(void);

	int GetLif(void);
	Vector2 GetPos(void);
	Vector2 GetSize(void);
	Vector2 GetShotPos(void);

	bool mPush;
	bool mPush2;
	bool mPush3;
	bool mPush4;

	bool mEnemy1;
	bool mEnemy2;
	bool mEnemy3;
	bool mEnemy4;

	bool ShotAlive1;
	bool ShotAlive2;
	bool ShotAlive3;
	bool ShotAlive4;

	int mCnt;
	int mCnt2;
	int mCnt3;
	int mCnt4;

	
};

