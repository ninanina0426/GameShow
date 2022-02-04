#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "../_debug/_DebugConOut.h"
#include "../_debug/_DebugDispOut.h"

constexpr int ScreenSizeX = 800;
constexpr int ScreenSizeY = 650;
//SceneMng* SceneMng::s_Instance = nullptr;

void SceneMng::Run(void)
{

	if (!InitFlag_)
	{
		if (!SysInit())//�ēx���s�Ȃ甲����
		{
			return;
		}
	}
	
	//�����V�[���̃C���X�^���X
	scene_ = std::make_unique<TitleScene>();
	

	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) //ProcessMessage()�̓E�B���h�E�Ƀ��b�Z�[�W�𑗂�
	{
		_dbgStartDraw();
		scene_ = scene_->Update(std::move(scene_));

		

		SetDrawScreen(DX_SCREEN_BACK);//�]�ʂ��邾���̃o�b�N�o�b�t�@
		ClsDrawScreen();
		
		scene_->Draw();
		_dbgDraw();
		ScreenFlip();
	}
}

void SceneMng::Update(void)
{

	
}

void SceneMng::Draw(void)
{
}

bool SceneMng::SysInit(void)
{
	SetWindowText("ASOGAME");
	//�V�X�e������
	SetGraphMode(ScreenSizeX, ScreenSizeY, 16);			//1280�~720�h�b�g65536�F���[�h�ɐݒ�
	ChangeWindowMode(true);				//true:window false:�t���X�N���[��

	//DX���C�u��������������
	if (DxLib_Init() == -1)
	{
		return false;
	}
	_dbgSetup(ScreenSizeX, ScreenSizeY, 255);
	
	
	return true;
}



SceneMng::SceneMng()
{
	InitFlag_ = SysInit();
	
}

SceneMng::~SceneMng()
{
}
