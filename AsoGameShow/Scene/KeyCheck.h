//#pragma once
//class KeyCheck
//{
//};

//定義
enum KEY_LIST			//ゲーム内で利用するキー情報
{
	//システム　キー情報
	KEY_SYS_START,

	//Player1　キー情報
	KEY_P1_UP,
	KEY_P1_DOWN,
	KEY_P1_LEFT,
	KEY_P1_RIGHT,
	KEY_P1_A,
	KEY_P1_B,
	KEY_P1_C,
	KEY_P1_P,
	//Player2　キー情報
	KEY_P2_UP,
	KEY_P2_DOWN,
	KEY_P2_LEFT,
	KEY_P2_RIGHT,
	KEY_P2_A,
	KEY_P2_B,

	KEY_LIST_MAX
};

extern bool keyNew[KEY_LIST_MAX];			//現フレームのキー状態
extern bool keyTrgDown[KEY_LIST_MAX];		//KeyDownのトリガー状態
extern bool keyTrgUp[KEY_LIST_MAX];		//KeyUpのトリガー状態



//プロトタイプ宣言
void KeyInit(void);			//キー情報の作成初期化
void CheckKeyList(void);		//キー情報の