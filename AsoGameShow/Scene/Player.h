#pragma once
#include "common/Vector2.h"
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
	Vector2 mPos;		//キャラクターの地図上の座標
	Vector2 mSizeOffset;//キャラクターのオフセットサイズ　　半分の値
	Vector2 mSize;		//キャラクター画像のサイズ
	int mMoveSpeed;		//キャラクター移動スピード
	int mAnmCnt;		//キャラクターのアニメーション

	
	int mCnt;
	//
	int mDCnt;
	Vector2 mDorPos;
	bool mDor;
public:
	int mPosBottom;	//キャラクターの足元のY座標

	bool init(GameScene* parent);		//初期化
	Vector2 Update(void);		//更新
	void Draw(Vector2 offset);		//描画
	bool Release(void);		//開放
	bool IsAlive(void);
	void SetPos(Vector2 pos);
	Vector2 GetSiz(void);
	DIR GetDIR(void);

	Vector2 GetPlayerPos(void);
};

