//#pragma once
//class KeyCheck
//{
//};

//��`
enum KEY_LIST			//�Q�[�����ŗ��p����L�[���
{
	//�V�X�e���@�L�[���
	KEY_SYS_START,

	//Player1�@�L�[���
	KEY_P1_UP,
	KEY_P1_DOWN,
	KEY_P1_LEFT,
	KEY_P1_RIGHT,
	KEY_P1_A,
	KEY_P1_B,
	KEY_P1_C,
	KEY_P1_P,
	//Player2�@�L�[���
	KEY_P2_UP,
	KEY_P2_DOWN,
	KEY_P2_LEFT,
	KEY_P2_RIGHT,
	KEY_P2_A,
	KEY_P2_B,

	KEY_LIST_MAX
};

extern bool keyNew[KEY_LIST_MAX];			//���t���[���̃L�[���
extern bool keyTrgDown[KEY_LIST_MAX];		//KeyDown�̃g���K�[���
extern bool keyTrgUp[KEY_LIST_MAX];		//KeyUp�̃g���K�[���



//�v���g�^�C�v�錾
void KeyInit(void);			//�L�[���̍쐬������
void CheckKeyList(void);		//�L�[����