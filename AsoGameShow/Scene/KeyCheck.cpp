#include "KeyCheck.h"
#include<time.h>
#include"DxLib.h"




//�ϐ��̒�`
bool keyOld[KEY_LIST_MAX];			//�P�t���[���O�̃L�[���
bool keyNew[KEY_LIST_MAX];			//���t���[���̃L�[���
bool keyTrgDown[KEY_LIST_MAX];		//KeyDown�̃g���K�[���
bool keyTrgUp[KEY_LIST_MAX];		//KeyUp�̃g���K�[���


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
	//�@�P�t���[���O�̃f�[�^���R�s�[����B�FkeyOld
	//���̑��̕ϐ��͏�����
	
	for (int x = 0; x < KEY_LIST_MAX; x++)
	{
		keyOld[x] = keyNew[x];
		keyNew[x] = false;
		keyTrgDown[x] = false;
		keyTrgUp[x] = false;
	}
		//�A���t���[���̏�Ԃ��������i�[�FKeyNew
		
		keyNew[KEY_SYS_START] = CheckHitKey(KEY_INPUT_SPACE);
		keyNew[KEY_P1_UP] = CheckHitKey(KEY_INPUT_UP);
		keyNew[KEY_P1_DOWN] = CheckHitKey(KEY_INPUT_DOWN);
		keyNew[KEY_P1_LEFT] = CheckHitKey(KEY_INPUT_LEFT);
		keyNew[KEY_P1_RIGHT] = CheckHitKey(KEY_INPUT_RIGHT);
		keyNew[KEY_P1_A ]= CheckHitKey(KEY_INPUT_N);
		keyNew[KEY_P1_B] = CheckHitKey(KEY_INPUT_M);
		keyNew[KEY_P1_C] = CheckHitKey(KEY_INPUT_B);
		keyNew[KEY_P1_P] = CheckHitKey(KEY_INPUT_P);
		//Player2�@�L�[���
		keyNew[KEY_P2_UP] = CheckHitKey(KEY_INPUT_W);
		keyNew[KEY_P2_DOWN] = CheckHitKey(KEY_INPUT_S);
		keyNew[KEY_P2_LEFT] = CheckHitKey(KEY_INPUT_A);
		keyNew[KEY_P2_RIGHT] = CheckHitKey(KEY_INPUT_D);
		keyNew[KEY_P2_A] = CheckHitKey(KEY_INPUT_LCONTROL);
		keyNew[KEY_P2_B] = CheckHitKey(KEY_INPUT_LSHIFT);

		/*keyNew[KEY_LIST_MAX] = CheckHitKey(KEY_INPUT_D);*/

		//�B�g���K�[�̏�Ԃ��`�F�b�N���i�[�FkeyTrgDown,keyTrgUp
		for (int x = 0; x < KEY_LIST_MAX; x++)
		{
		/*	if (keyNew[x] == 1 && keyOld[x] == 0)
			{
				keyTrgDown[x] = true;
			}*/

			// ~���r�b�g���]������A�`���_�[
			//�_�����Z

			keyTrgDown[x] = keyNew[x] & ~keyOld[x];
			keyTrgUp[x] = ~keyNew[x] & keyOld[x];

			/*if (keyNew[x] == 0 && keyOld[x] == 1)
			{
				keyTrgUp[x] = true;
			}*/
		}
		
		

	
}

