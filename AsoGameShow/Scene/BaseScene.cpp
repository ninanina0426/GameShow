#include <DxLib.h>
#include "BaseScene.h"


BaseScene::BaseScene()
{
	//Init();�����ŌĂԂƌp����ŌĂіY��Ă����v
	SetDrawScreen(DX_SCREEN_BACK);//�����I�ɂǂ̃X�N���[���Ȃ̂�
	GetDrawScreenSize(&screenSize_.x_, &screenSize_.y_);//�`���̃T�C�Y�擾
	sceneScrID_ = MakeScreen(screenSize_.x_, screenSize_.y_, true);
	
}

BaseScene::~BaseScene()
{
}

void BaseScene::Draw()
{
	DrawGraph(0, 0, sceneScrID_, true);//���ꂼ��̃V�[����`��
}


