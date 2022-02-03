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

	bool mPush;


	DIR mMoveDir;		//�L�����N�^�[�̌���
	Vector2d mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2d mSizeOffset;//�L�����N�^�[�̃I�t�Z�b�g�T�C�Y�@�@�����̒l
	Vector2d mSize;		//�L�����N�^�[�摜�̃T�C�Y
	int mMoveSpeed;		//�L�����N�^�[�ړ��X�s�[�h
	int mAnmCnt;		//�L�����N�^�[�̃A�j���[�V����

	int mCnt;
public:
	int mPosBottom;	//�L�����N�^�[�̑�����Y���W

	bool init(GameScene* parent);		//������
	Vector2d Update(void);		//�X�V
	void Draw(void);		//�`��
	bool Release(void);		//�J��
	DIR GetDIR(void);
};

