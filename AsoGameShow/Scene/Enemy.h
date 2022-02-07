#pragma once
#include "common/Vector2.h"
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
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2 mSizeOffset;//�L�����N�^�[�̃I�t�Z�b�g�T�C�Y�@�@�����̒l
	Vector2 mSize;		//�L�����N�^�[�摜�̃T�C�Y
	int mMoveSpeed;		//�L�����N�^�[�ړ��X�s�[�h
	int mAnmCnt;		//�L�����N�^�[�̃A�j���[�V����

	Vector2 plPos_;


	//�e�֘A�i�N���X����Ă��������ǂ�����Ƃ߂�ǂ��H�j
	//Vector2 bulletPos_[4];
	Vector2 bulletPos_;

	int Speed_;
	int BulletID_[256];
	int count_;
	//bool BulletFlag_[4];
	bool BulletFlag_;

	DIR bulletDir_;
	Vector2 ShotPos;
public:
	int mPosBottom;	//�L�����N�^�[�̑�����Y���W

	bool init(GameScene* parent);		//������
	Vector2 Update(Vector2 player);		//�X�V
	void Draw(void);		//�`��
	bool Release(void);		//�J��
	DIR GetDIR(void);
	bool IsAlive(void);
//<<<<<<< HEAD
//	Vector2d GetPos(void);
//	Vector2d GetSize(void);
//
	void IsDestry(void);

	int GetLif(void);
	Vector2 GetPos(void);
	Vector2 GetSize(void);
	Vector2 GetShotPos(void);

	bool mPush;
	bool mPush2;
	bool mPush3;
	bool mPush4;

	bool mEnemy1;
	bool mEnemy2;
	bool mEnemy3;
	bool mEnemy4;

	bool ShotAlive1;
	bool ShotAlive2;
	bool ShotAlive3;
	bool ShotAlive4;

	int mCnt;
	int mCnt2;
	int mCnt3;
	int mCnt4;

	
};

