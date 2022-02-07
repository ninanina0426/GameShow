#pragma once
#include "common/Vector2.h"
#include "GameCommon.h"

#define CHIP_CNT_MAX 840
#define CHIP_X_MAX 20
#define CHIP_Y_MAX 42
#define MAP_X 20
#define MAP_Y 15


class Stage
{
private://メンバ関数

	int mMapX;				//現在のマップの横サイズ
	int mMapY;				//現在のマップの縦サイズ
	int mMap[MAP_Y][MAP_X];	//現在のマップデータ
	int mMapYuka[MAP_Y][MAP_X];	//現在のマップデータ
	int mMapKagu[MAP_Y][MAP_X];	//現在のマップデータ
	int mStringWidth;//文字列のピクセル描画
	int mChipImage[CHIP_CNT_MAX];
	
	Vector2 mOffset;
	
	

	bool mFadeOut;
	bool mFadeIn;


public://メンバ関数

	bool Init(void);				//インスタンスの初期化
	Vector2 Update(Vector2 mPlayerset);//インスタンスの更新処理
	void Draw(void);				//インスタンスの描画
	bool Release(void);				//インスタンスの開放
	int GetMapChip(Vector2 Pos);	//座標を指定してマップチップデータをもらう
	void SetMap(void);		//マップデータをｍMapに設定する
	void subInit(void);


};

