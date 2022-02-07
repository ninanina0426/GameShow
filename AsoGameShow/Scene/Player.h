#pragma once
#include "common/Vector2.h"
#include "GameCommon.h"
class GameScene;

class Player
{
private:
	
	GameScene* mParent;

	int mImage[16];		//�摜�̊i�[�̈�
	int mImage2[16];		//�摜�̊i�[�̈�
	int mImage3[4];		//�摜�̊i�[�̈�
	int mImage4[4];		//�摜�̊i�[�̈�

	bool mPush;
	int mLife;			//�L�����N�^�[�̗̑�
	int mLifeMax;		//�L�����N�^�[�̍ő�̗͒l

	DIR mMoveDir;		//�L�����N�^�[�̌���
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2 mSizeOffset;//�L�����N�^�[�̃I�t�Z�b�g�T�C�Y�@�@�����̒l
	Vector2 mSize;		//�L�����N�^�[�摜�̃T�C�Y
	int mMoveSpeed;		//�L�����N�^�[�ړ��X�s�[�h
	int mAnmCnt;		//�L�����N�^�[�̃A�j���[�V����

	
	int mCnt;
	//
	int mDCnt;
	Vector2 mDorPos;
	bool mDor;
public:
	int mPosBottom;	//�L�����N�^�[�̑�����Y���W

	bool init(GameScene* parent);		//������
	Vector2 Update(void);		//�X�V
	void Draw(Vector2 offset);		//�`��
	bool Release(void);		//�J��
	bool IsAlive(void);
	void SetPos(Vector2 pos);
	Vector2 GetSiz(void);
	DIR GetDIR(void);

	Vector2 GetPlayerPos(void);
};

