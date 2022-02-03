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
	date_["エディット"] = CheckHitKey(joyTbl_["エディット"]);
	return false;
}

bool JoyPad::init()
{
	joyTbl_["上"] = PAD_INPUT_UP;
	joyTbl_["下"] = PAD_INPUT_DOWN;
	joyTbl_["左"] = PAD_INPUT_LEFT;
	joyTbl_["右"] = PAD_INPUT_RIGHT;
	joyTbl_["Ａ"] = PAD_INPUT_1;

	joyTbl_["エディット"] = KEY_INPUT_F6;

	for (auto joyData : joyTbl_)
	{
		date_.emplace(joyData.first, 0);
	}


	
	return false;
}
