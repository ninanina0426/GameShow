#pragma once
#include"Vector2d.h"
#include "GameCommon.h"

#define CHIP_CNT_MAX 840
#define CHIP_X_MAX 20
#define CHIP_Y_MAX 42
#define MAP_X 20
#define MAP_Y 15


class Stage
{
private://�����o�֐�

	int mMapX;				//���݂̃}�b�v�̉��T�C�Y
	int mMapY;				//���݂̃}�b�v�̏c�T�C�Y
	int mMap[MAP_Y][MAP_X];	//���݂̃}�b�v�f�[�^
	int mMapYuka[MAP_Y][MAP_X];	//���݂̃}�b�v�f�[�^
	int mMapKagu[MAP_Y][MAP_X];	//���݂̃}�b�v�f�[�^
	int mStringWidth;//������̃s�N�Z���`��
	int mChipImage[CHIP_CNT_MAX];
	
	Vector2d mOffset;
	//int mOffsetX;		//�J������X���W
	//int mOffsetY;		//�J������Y���W

	bool mFadeOut;
	bool mFadeIn;


public://�����o�֐�

	bool Init(void);				//�C���X�^���X�̏�����
	Vector2d Update(Vector2d mPlayerset);//�C���X�^���X�̍X�V����
	void Draw(void);				//�C���X�^���X�̕`��
	bool Release(void);				//�C���X�^���X�̊J��
	int GetMapChip(Vector2d Pos);	//���W���w�肵�ă}�b�v�`�b�v�f�[�^�����炤
	void SetMap(void);		//�}�b�v�f�[�^����Map�ɐݒ肷��
	void subInit(void);
};

