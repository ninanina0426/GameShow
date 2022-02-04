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
		if (!SysInit())//再度失敗なら抜ける
		{
			return;
		}
	}
	
	//初期シーンのインスタンス
	scene_ = std::make_unique<TitleScene>();
	

	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) //ProcessMessage()はウィンドウにメッセージを送る
	{
		_dbgStartDraw();
		scene_ = scene_->Update(std::move(scene_));

		

		SetDrawScreen(DX_SCREEN_BACK);//転写するだけのバックバッファ
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
	//システム処理
	SetGraphMode(ScreenSizeX, ScreenSizeY, 16);			//1280×720ドット65536色モードに設定
	ChangeWindowMode(true);				//true:window false:フルスクリーン

	//DXライブラリ初期化処理
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
