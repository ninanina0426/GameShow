#include <DxLib.h>
#include "Keyboard.h"

KeyBoard::KeyBoard()
{
	init();
}

KeyBoard::~KeyBoard()
{
}

bool KeyBoard::Update(Obj& obj)
{
	for (auto& data : date_)
	{
		dateOld_[data.first] = data.second;
	}
	
	GetHitKeyStateAll(KeyData_);//すべてのキー情報を取得してkeyDataに入れる
	for (auto tblData : keyTbl_)
	{
		date_[tblData.first] = KeyData_[tblData.second];//data_["firstの情報(キーIDの情報）"]=KeyData_[sesondの情報 (keyTbl_[""])]と同じこと
		
	}
	return true;
}

bool KeyBoard::init(void)
{
	keyTbl_["上"] = KEY_INPUT_UP;
	keyTbl_["下"] = KEY_INPUT_DOWN;
	keyTbl_["右"] = KEY_INPUT_RIGHT;
	keyTbl_["左"] = KEY_INPUT_LEFT;
	keyTbl_["Ａ"] = KEY_INPUT_Z;
	keyTbl_["エディット"] = KEY_INPUT_F6;

	for (auto tblData : keyTbl_)
	{
		date_.emplace(tblData.first, 0);
		
	}

	//キーコンフィグするときはifとelseでファイルを

	return true;
}
