#pragma once
#include "BaseScene.h"

#define lpSceneMng SceneMng::GetInstance()


class SceneMng
{
public:
	static SceneMng& GetInstance()
	{
		static SceneMng s_Instance;
		return s_Instance;
	}
	void Run(void);
	void Update(void);
	void Draw(void);
private:
	bool SysInit(void);
	bool InitFlag_;//システムの処理が正常か

	//static SceneMng s_Instance;
	SceneMng();
	~SceneMng();
	uniquBaseScn  scene_;//シーン管理
};

