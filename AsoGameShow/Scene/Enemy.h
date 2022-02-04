#pragma once
#include"Vector2d.h"
#include "GameCommon.h"
class GameScene;

class Enemy
{
private:

	GameScene* mParent;

	int mImage[16];		//�摜�̊i�[�̈�
	int mImage2[16];		//�摜�̊i�[�̈�
	int mImage3[16];		//�摜�̊i�[�̈�
	int mImage4[16];		//�摜�̊i�[�̈�

	int mDedImage[16];		//�摜�̊i�[�̈�
	int mDedImage2[16];		//�摜�̊i�[�̈�
	int mDedImage3[16];		//�摜�̊i�[�̈�
	int mDedImage4[16];		//�摜�̊i�[�̈�

	
	
	int mLife;			//�L�����N�^�[�̗̑�
	int mLifeMax;		//�L�����N�^�[�̍ő�̗͒l

	DIR mMoveDir;		//�L�����N�^�[�̌���
	Vector2d mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2d mSizeOffset;//�L�����N�^�[�̃I�t�Z�b�g�T�C�Y�@�@�����̒l
	Vector2d mSize;		//�L�����N�^�[�摜�̃T�C�Y
	int mMoveSpeed;		//�L�����N�^�[�ړ��X�s�[�h
	int mAnmCnt;		//�L�����N�^�[�̃A�j���[�V����

public:
	int mPosBottom;	//�L�����N�^�[�̑�����Y���W

	bool init(GameScene* parent);		//������
	Vector2d Update(void);		//�X�V
	void Draw(void);		//�`��
	bool Release(void);		//�J��
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

