#pragma once
#include"Vector2d.h"
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
	Vector2d mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2d mSizeOffset;//�L�����N�^�[�̃I�t�Z�b�g�T�C�Y�@�@�����̒l
	Vector2d mSize;		//�L�����N�^�[�摜�̃T�C�Y
	int mMoveSpeed;		//�L�����N�^�[�ړ��X�s�[�h
	int mAnmCnt;		//�L�����N�^�[�̃A�j���[�V����

	int mCnt;
	//
	int mDCnt;
	Vector2d mDorPos;
	bool mDor;
public:
	int mPosBottom;	//�L�����N�^�[�̑�����Y���W

	bool init(GameScene* parent);		//������
	Vector2d Update(void);		//�X�V
	void Draw(Vector2d offset);		//�`��
	bool Release(void);		//�J��
	bool IsAlive(void);
	void SetPos(Vector2d pos);
	Vector2d GetSiz(void);
	DIR GetDIR(void);
};

