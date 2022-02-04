#pragma once
#include <map>
#include <string>
#include <list>
#include "Vector2.h"

#define lpAnimMng AnimMng::GetInstance()

using AnimData = std::pair<int, int>;
//using AnimData = std::array<int, 2>;//グラフィックハンドル、時間
using AnimNode = std::pair<int, std::list<std::pair<int, int>>>;//再生回数、データの塊


using AnimItr = std::list< std::pair<int, int>>::iterator;
using AnimMap = std::map<std::string, AnimNode>;


struct AnimeData
{
	std::string objID_;
	std::string state_;
	AnimItr animItr_;
	int animCnt_;//アニメーションのframe数
	int animPlayCnt_;//iteratorは何回すすんだか
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
	AnimeData SetAnim(std::string ObjID,std::string state,bool LRFlag);//objIDも必要かも？


	
private:
	AnimMng();
	~AnimMng();
	AnimMap animTbl_;
	AnimeData animData_;
};


