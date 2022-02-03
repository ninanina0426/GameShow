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
	
	GetHitKeyStateAll(KeyData_);//���ׂẴL�[�����擾����keyData�ɓ����
	for (auto tblData : keyTbl_)
	{
		date_[tblData.first] = KeyData_[tblData.second];//data_["first�̏��(�L�[ID�̏��j"]=KeyData_[sesond�̏�� (keyTbl_[""])]�Ɠ�������
		
	}
	return true;
}

bool KeyBoard::init(void)
{
	keyTbl_["��"] = KEY_INPUT_UP;
	keyTbl_["��"] = KEY_INPUT_DOWN;
	keyTbl_["�E"] = KEY_INPUT_RIGHT;
	keyTbl_["��"] = KEY_INPUT_LEFT;
	keyTbl_["�`"] = KEY_INPUT_Z;
	keyTbl_["�G�f�B�b�g"] = KEY_INPUT_F6;

	for (auto tblData : keyTbl_)
	{
		date_.emplace(tblData.first, 0);
		
	}

	//�L�[�R���t�B�O����Ƃ���if��else�Ńt�@�C����

	return true;
}
