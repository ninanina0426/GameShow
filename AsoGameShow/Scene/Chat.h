#pragma once
#include"Vector2d.h"

class Chat
{
public:
	bool init(void);		//初期化
	bool Update(void);		//更新
	void Draw(void);		//描画
	bool Release(void);		//開放

	bool IsEnd;
private:
	int mImage[18];
	
	int mCnt;
	int x;
	
	
};

