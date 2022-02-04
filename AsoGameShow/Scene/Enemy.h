#pragma once
#include"Vector2d.h"
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
	Vector2d mPos;		//キャラクターの地図上の座標
	Vector2d mSizeOffset;//キャラクターのオフセットサイズ　　半分の値
	Vector2d mSize;		//キャラクター画像のサイズ
	int mMoveSpeed;		//キャラクター移動スピード
	int mAnmCnt;		//キャラクターのアニメーション

public:
	int mPosBottom;	//キャラクターの足元のY座標

	bool init(GameScene* parent);		//初期化
	Vector2d Update(void);		//更新
	void Draw(void);		//描画
	bool Release(void);		//開放
	DIR GetDIR(void);
	bool IsAlive(void);
	Vector2d GetPos(void);
	Vector2d GetSize(void);

	bool mPush;
	bool mPush2;
	bool mPush3;
	bool mPush4;

	bool mEnemy1;
	bool mEnemy2;
	bool mEnemy3;
	bool mEnemy4;

	int mCnt;
	int mCnt2;
	int mCnt3;
	int mCnt4;
};

