#include <DxLib.h>
#include "JoyPad.h"

JoyPad::JoyPad()
{
	init();
}

JoyPad::~JoyPad()
{

}

bool JoyPad::Update(Obj& obj)
{
	auto inputData = GetJoypadInputState(DX_INPUT_PAD1);

	for (auto tblData : joyTbl_)
	{
		date_[tblData.first] = inputData& tblData.second;
	}
	date_["�G�f�B�b�g"] = CheckHitKey(joyTbl_["�G�f�B�b�g"]);
	return false;
}

bool JoyPad::init()
{
	joyTbl_["��"] = PAD_INPUT_UP;
	joyTbl_["��"] = PAD_INPUT_DOWN;
	joyTbl_["��"] = PAD_INPUT_LEFT;
	joyTbl_["�E"] = PAD_INPUT_RIGHT;
	joyTbl_["�`"] = PAD_INPUT_1;

	joyTbl_["�G�f�B�b�g"] = KEY_INPUT_F6;

	for (auto joyData : joyTbl_)
	{
		date_.emplace(joyData.first, 0);
	}


	
	return false;
}
