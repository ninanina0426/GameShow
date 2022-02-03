#pragma once
#include <map>
#include <string>
#include <list>
#include "Vector2.h"

#define lpAnimMng AnimMng::GetInstance()

using AnimData = std::pair<int, int>;
//using AnimData = std::array<int, 2>;//�O���t�B�b�N�n���h���A����
using AnimNode = std::pair<int, std::list<std::pair<int, int>>>;//�Đ��񐔁A�f�[�^�̉�


using AnimItr = std::list< std::pair<int, int>>::iterator;
using AnimMap = std::map<std::string, AnimNode>;


struct AnimeData
{
	std::string objID_;
	std::string state_;
	AnimItr animItr_;
	int animCnt_;//�A�j���[�V������frame��
	int animPlayCnt_;//iterator�͉��񂷂��񂾂�
	bool LRFlag_;
	//AnimMap animTbl_;
};


class AnimMng
{
public:
	static AnimMng& GetInstance()
	{
		static AnimMng s_Instance;
		return s_Instance;
	}
	
	const AnimMap GetAnimMap() { return animTbl_; };
	bool LoadAnime(std::string fileName,std::string ObjID);
	bool UpDateAnime(AnimeData& animeData);
	AnimeData SetAnim(std::string ObjID,std::string state,bool LRFlag);//objID���K�v�����H


	
private:
	AnimMng();
	~AnimMng();
	AnimMap animTbl_;
	AnimeData animData_;
};


