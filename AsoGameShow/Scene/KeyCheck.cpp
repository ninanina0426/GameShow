#include "KeyCheck.h"
#include<time.h>
#include"DxLib.h"




//変数の定義
bool keyOld[KEY_LIST_MAX];			//１フレーム前のキー状態
bool keyNew[KEY_LIST_MAX];			//現フレームのキー状態
bool keyTrgDown[KEY_LIST_MAX];		//KeyDownのトリガー状態
bool keyTrgUp[KEY_LIST_MAX];		//KeyUpのトリガー状態


void KeyInit(void)
{
	for (int x =0; x < KEY_LIST_MAX; x++)
	{
		keyOld[x] = false;
		keyNew[x] = false;
		keyTrgDown[x] = false;
		keyTrgUp[x] = false;
	}

}

void CheckKeyList(void)
{
	//①１フレーム前のデータをコピーする。：keyOld
	//その他の変数は初期化
	
	for (int x = 0; x < KEY_LIST_MAX; x++)
	{
		keyOld[x] = keyNew[x];
		keyNew[x] = false;
		keyTrgDown[x] = false;
		keyTrgUp[x] = false;
	}
		//②現フレームの状態を所得し格納：KeyNew
		
		keyNew[KEY_SYS_START] = CheckHitKey(KEY_INPUT_SPACE);
		keyNew[KEY_P1_UP] = CheckHitKey(KEY_INPUT_UP);
		keyNew[KEY_P1_DOWN] = CheckHitKey(KEY_INPUT_DOWN);
		keyNew[KEY_P1_LEFT] = CheckHitKey(KEY_INPUT_LEFT);
		keyNew[KEY_P1_RIGHT] = CheckHitKey(KEY_INPUT_RIGHT);
		keyNew[KEY_P1_A ]= CheckHitKey(KEY_INPUT_N);
		keyNew[KEY_P1_B] = CheckHitKey(KEY_INPUT_M);
		keyNew[KEY_P1_C] = CheckHitKey(KEY_INPUT_B);
		keyNew[KEY_P1_P] = CheckHitKey(KEY_INPUT_P);
		//Player2　キー情報
		keyNew[KEY_P2_UP] = CheckHitKey(KEY_INPUT_W);
		keyNew[KEY_P2_DOWN] = CheckHitKey(KEY_INPUT_S);
		keyNew[KEY_P2_LEFT] = CheckHitKey(KEY_INPUT_A);
		keyNew[KEY_P2_RIGHT] = CheckHitKey(KEY_INPUT_D);
		keyNew[KEY_P2_A] = CheckHitKey(KEY_INPUT_LCONTROL);
		keyNew[KEY_P2_B] = CheckHitKey(KEY_INPUT_LSHIFT);

		/*keyNew[KEY_LIST_MAX] = CheckHitKey(KEY_INPUT_D);*/

		//③トリガーの状態をチェックし格納：keyTrgDown,keyTrgUp
		for (int x = 0; x < KEY_LIST_MAX; x++)
		{
		/*	if (keyNew[x] == 1 && keyOld[x] == 0)
			{
				keyTrgDown[x] = true;
			}*/

			// ~←ビット反転させる、チルダー
			//論理演算

			keyTrgDown[x] = keyNew[x] & ~keyOld[x];
			keyTrgUp[x] = ~keyNew[x] & keyOld[x];

			/*if (keyNew[x] == 0 && keyOld[x] == 1)
			{
				keyTrgUp[x] = true;
			}*/
		}
		
		

	
}

