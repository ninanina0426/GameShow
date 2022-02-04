#include <DxLib.h>
#include "../../tmx/rapidxml.hpp"
#include "../../tmx/rapidxml_utils.hpp"
#include "ImageMng.h"
#include "AnimMng.h"
#include "../../_debug/_DebugConOut.h"

AnimMng::AnimMng()
{
}

AnimMng::~AnimMng()
{
}

bool AnimMng::LoadAnime(std::string fileName,std::string objID)
{
	
	//アニメーションファイルの読み込み
	rapidxml::xml_document<> xmlDoc_;

	rapidxml::file<> xmlFileName =fileName.c_str();//ファイル読み込みデータを格納
	xmlDoc_.parse<0>(xmlFileName.data());

	rapidxml::xml_node<>* Obj_node = xmlDoc_.first_node("Obj");
	if (Obj_node == nullptr)
	{
		return false;
	}
	std::string verstion = Obj_node->first_attribute("version")->value();
	if (verstion != "1.0")
	{
		return false;
	}

	//std::string objID = ;
	auto ObjID = Obj_node->first_node(objID.c_str());
	auto image = ObjID->first_node("image");
	for (auto actionList_ = image->first_node("act"); actionList_ != nullptr; actionList_ = actionList_->next_sibling())
	{
		lpImageMng.GetID(
			image->first_attribute("path")->value(),
			image->first_attribute("key")->value(),
			Vector2{ atoi(image->first_attribute("PLsizeX")->value()),atoi(image->first_attribute("PLsizeY")->value()) },
			Vector2{ atoi(image->first_attribute("PLcnt")->value()),atoi(image->first_attribute("PLhig")->value()) });
		//auto actionList_ = image->first_node("act");

		std::string Id = actionList_->first_attribute("name")->value();//Idの名前を取得
		animTbl_.try_emplace(Id);
		animTbl_[Id].first = atoi(actionList_->first_attribute("loop")->value());//ループ回数を格納
		for (auto animData = actionList_->first_node(); animData != nullptr; animData = animData->next_sibling())
		{
			auto id = atoi(animData->first_attribute("id")->value());
			auto fream = atoi(animData->first_attribute("time")->value());
			animTbl_[Id].second.emplace_back(id, fream);
		}
		//auto animData = actionList_->first_node("deta");

	}
	return true;
}

bool AnimMng::UpDateAnime(AnimeData& animeData)
{
	//アニメーションのアップデート
	if (animData_.LRFlag_)//ここは絶対false
	{
		//画像反転
		TRACE("反転\n");
	}
	if (animeData.animCnt_++ >= (*animeData.animItr_).second)
	{
		animeData.animCnt_ = 0;
		++animeData.animItr_;
		
		if (animeData.animItr_ == animTbl_[animeData.state_].second.end())//AnimDataの最後の要素にだどりついたか
		{
			if (++animeData.animPlayCnt_ < animTbl_[animeData.state_].first || animTbl_[animeData.state_].first == -1)//アニメーション回数無限？回数制限あり？
			{
				//ループ時

				animeData.animItr_ = animTbl_[animeData.state_].second.begin();
			}
			else
			{
				//最後のコマまで来た時
				animeData.animItr_ = --animTbl_[animeData.state_].second.end();//最後のコマの絵で止める
			}
		}
	}
	return true;
}

AnimeData AnimMng::SetAnim(std::string ObjID,std::string state, bool LRFlag )
{
	//読み込んだ内容に対してのアニメーション使用時の初期化
	return AnimeData{
		ObjID,
		state, 
		animTbl_[state].second.begin(),
		0,
		0,
		LRFlag
	};
	
}




