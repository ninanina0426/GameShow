#pragma once
#include"Vector2d.h"
#include "GameCommon.h"
class GameScene;

class Player
{
private:
	
	GameScene* mParent;

	int mImage[16];		//画像の格納領域
	int mImage2[16];		//画像の格納領域
	int mImage3[4];		//画像の格納領域
	int mImage4[4];		//画像の格納領域

	bool mPush;
	int mLife;			//キャラクターの体力
	int mLifeMax;		//キャラクターの最大体力値

	DIR mMoveDir;		//キャラクターの向き
	Vector2d mPos;		//キャラクターの地図上の座標
	Vector2d mSizeOffset;//キャラクターのオフセットサイズ　　半分の値
	Vector2d mSize;		//キャラクター画像のサイズ
	int mMoveSpeed;		//キャラクター移動スピード
	int mAnmCnt;		//キャラクターのアニメーション

	int mCnt;
	//
	int mDCnt;
	Vector2d mDorPos;
	bool mDor;
public:
	int mPosBottom;	//キャラクターの足元のY座標

	bool init(GameScene* parent);		//初期化
	Vector2d Update(void);		//更新
	void Draw(Vector2d offset);		//描画
	bool Release(void);		//開放
	bool IsAlive(void);
	void SetPos(Vector2d pos);
	Vector2d GetSiz(void);
	DIR GetDIR(void);
};

