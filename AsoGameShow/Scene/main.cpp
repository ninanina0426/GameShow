#include <DxLib.h>
//#include "Scene/SceneMng.h"
#include "SceneMng.h"
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) //_In_をつけると波線が消える
{
	lpSceneMng.Run();
	return 0;
}

