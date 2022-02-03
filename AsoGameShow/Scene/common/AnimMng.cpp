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
	
	//�A�j���[�V�����t�@�C���̓ǂݍ���
	rapidxml::xml_document<> xmlDoc_;

	rapidxml::file<> xmlFileName =fileName.c_str();//�t�@�C���ǂݍ��݃f�[�^���i�[
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

		std::string Id = actionList_->first_attribute("name")->value();//Id�̖��O���擾
		animTbl_.try_emplace(Id);
		animTbl_[Id].first = atoi(actionList_->first_attribute("loop")->value());//���[�v�񐔂��i�[
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
	//�A�j���[�V�����̃A�b�v�f�[�g
	if (animData_.LRFlag_)//�����͐��false
	{
		//�摜���]
		TRACE("���]\n");
	}
	if (animeData.animCnt_++ >= (*animeData.animItr_).second)
	{
		animeData.animCnt_ = 0;
		++animeData.animItr_;
		
		if (animeData.animItr_ == animTbl_[animeData.state_].second.end())//AnimData�̍Ō�̗v�f�ɂ��ǂ������
		{
			if (++animeData.animPlayCnt_ < animTbl_[animeData.state_].first || animTbl_[animeData.state_].first == -1)//�A�j���[�V�����񐔖����H�񐔐�������H
			{
				//���[�v��

				animeData.animItr_ = animTbl_[animeData.state_].second.begin();
			}
			else
			{
				//�Ō�̃R�}�܂ŗ�����
				animeData.animItr_ = --animTbl_[animeData.state_].second.end();//�Ō�̃R�}�̊G�Ŏ~�߂�
			}
		}
	}
	return true;
}

AnimeData AnimMng::SetAnim(std::string ObjID,std::string state, bool LRFlag )
{
	//�ǂݍ��񂾓��e�ɑ΂��ẴA�j���[�V�����g�p���̏�����
	return AnimeData{
		ObjID,
		state, 
		animTbl_[state].second.begin(),
		0,
		0,
		LRFlag
	};
	
}




