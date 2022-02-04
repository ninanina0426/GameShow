#include <DxLib.h>
#include "ImageMng.h"
#include "../../_debug/_DebugConOut.h"

const VecInt& ImageMng::GetID(std::string key)
{
	GetID(key, key);
	//if (imageMap_.count(key) == 0)
	//{
	//	//�ǂݍ���ł��Ȃ��ꍇ
	//	imageMap_[key].resize(1);//VecInt�̃T�C�Y���m�肳����
	//	imageMap_[key][0] = LoadGraph(key.c_str());//VecInt�Ȃ̂Ŕz��̐擪�ɓǂݍ���
	//}
	return imageMap_[key];//�摜��Ԃ�
	
}

const VecInt& ImageMng::GetID(std::string f_name, std::string key, Vector2 divSize, Vector2 divCnt)
{
	if (imageMap_.count(key) == 0)
	{
		//�ǂݍ���ł��Ȃ��ꍇ
		imageMap_[key].resize(divCnt.x_ * divCnt.y_);//static_cast<UINT64>�������Ǝ��� �^���ӂ�����Ă���הg��
		if (LoadDivGraph(
			f_name.c_str(),
			divCnt.x_ * divCnt.y_,
			divCnt.x_, divCnt.y_,
			divSize.x_, divSize.y_,
			&imageMap_[key][0],
			true) == -1)
		{
			TRACE("�摜�ǂݍ��ݎ��s�F%s\n", f_name.c_str());
		}
	}
	return imageMap_[key];
}

const VecInt& ImageMng::GetID(std::string f_name, std::string key)
{
	if (imageMap_.count(key) == 0)
	{
		//�ǂݍ���ł��Ȃ��ꍇ
		imageMap_[key].resize(1);//VecInt�̃T�C�Y���m�肳����
		imageMap_[key][0] = LoadGraph(f_name.c_str());//VecInt�Ȃ̂Ŕz��̐擪�ɓǂݍ���
	}
	return imageMap_[key];//�摜��Ԃ�
}

ImageMng::ImageMng()
{
}

ImageMng::~ImageMng()
{
}
