#include <sstream>
#include "TmxObj.h"
#include "../Scene/common/ImageMng.h"
#include "../_debug/_DebugConOut.h"

TmxObj::TmxObj()
{
	//�Ή����Ă���o�[�W�������i�[����
	virsion_["1.7.2"] = 1;
	
}

TmxObj::~TmxObj()
{
}

bool TmxObj::LoadTSX(std::string fileName)
{
	rapidxml::file<> xmlFileName = fileName.c_str();//�f�[�^���i�[
	tsxDoc_.parse<0>(xmlFileName.data());

	rapidxml::xml_node<>* tileset = tsxDoc_.first_node("tileset");//�擪�̃m�[�h���擾����
	//auto tiledversion = tileset->first_attribute("tiledversion");//�擪�̃A�g���r���[�g���擾

	//�o�[�W�����`�F�b�N
	if (!ChackTiledVersion(tileset))
	{
		return false;
	}
	
	//��ԏ��߂̃m�[�h���E���Ă���
	auto node = tsxDoc_.first_node();
	
	
	while (node)//���g���Ȃ���nullptr���Ԃ��Ă���
	{
		if (node->name_size())//���O�̕����񒷎擾
		{
			//�f�o�b�O�p
			TRACE("%s��", node->name());
		}
		//�e�̃m�[�h��T��
		auto atr = node->first_attribute();
		
		while (atr)
		{
			if (atr->name_size())
			{
				//���O�̎擾
				TRACE("%s:", atr->name());
			}
			//���g�̎擾
			TRACE("%s ", atr->value());
			//���̃A�g���r���[�g��
			atr=atr->next_attribute();
		}
		TRACE("\n");
		//���̃m�[�h��
		node = node->next_sibling();
	}
	
	/*auto tileID = tileset->first_node("tile");
	auto image = tileID->first_node("image");*/
	auto image = tileset->first_node("image");
	std::string source=image->first_attribute("source")->value();//�t�@�C����
	auto keyName = source.substr(source.find_last_of("/")+1);//substr=����̈ʒu�̏����擾
	auto tilieWide = atoi(tileset->first_attribute("tilewidth")->value());//atoi=int�^�ɕϊ��`�b�v�̉��T�C�Y
	auto tilieHeigt = atoi(tileset->first_attribute("tileheight")->value());
	auto tiledivX = atoi(tileset->first_attribute("columns")->value());//���̑��`�b�v��
	auto tiledivY = atoi(tileset->first_attribute("tilecount")->value()) / tiledivX;//�^�C���̑��`�b�v��/���̑���

	lpImageMng.GetID(source, keyName, Vector2{ tilieWide ,tilieHeigt }, Vector2{ tiledivX,tiledivY});


	return true;
}

bool TmxObj::LoadTMX(std::string fileName)
{
	
	rapidxml::file<> xmlFileName = fileName.c_str();//�t�@�C���ǂݍ��݃f�[�^���i�[
	tmxDoc_.parse<0>(xmlFileName.data());
	
	rapidxml::xml_node<>* map_node = tmxDoc_.first_node("map");//�擪�̃m�[�h���擾����

	//�t�@�C���̃o�[�W�����`�F�b�N
	if (!ChackTiledVersion(map_node))
	{
		return false;
	}
	
	auto tileset= map_node->first_node("tileset");
	
	
	auto pass = fileName.substr(0,fileName.find_last_of("/") + 1);//substr=����̈ʒu�̏����擾
	auto tsxName = pass + tileset->first_attribute("source")->value();
	if (!LoadTSX(tsxName))
	{
		return false;
	}

	firstGID_ = atoi(tileset->first_attribute("firstgid")->value());
	layerSize_ = atoi(map_node->first_attribute("nextlayerid")->value())-1;
	worldArea_ = Vector2{ atoi(map_node->first_attribute("width")->value()),atoi(map_node->first_attribute("height")->value()) };
	tileSize_ = Vector2{ atoi(map_node->first_attribute("tilewidth")->value()),atoi(map_node->first_attribute("tileheight")->value()) };

	
	return SetMap();
}


bool TmxObj::SetMap(void)
{
	rapidxml::xml_node<>* map_node = tmxDoc_.first_node("map");//�����Ƀo�[�W�����m�F�����Ă�����
	if (map_node == nullptr)
	{
		TRACE("map�̃m�[�h�擾�G���[\n");
		return false;
	}
	//layer�̎擾����
	for (auto layernode = map_node->first_node("layer"); layernode != nullptr; layernode = layernode->next_sibling())
	{
		if (layernode == nullptr)
		{
			TRACE("map�m�[�h��layer�m�[�h�̎擾�G���[\n");
			return false;
		}
		std::string name = layernode->first_attribute("name")->value();
		if (name == "col")
		{
			continue;
		}
		auto layer = mapData_.try_emplace(layernode->first_attribute("name")->value());
		
		if (layer.second)
		{

			layer.first->second.resize(worldArea_.x_ * worldArea_.y_);

		}
		
		auto layerData = layernode->first_node("data")->first_node();//csv�`���̃f�[�^�������Ă���

		std::stringstream dataStream;
		dataStream << layerData->value();

		for (auto& data : layer.first->second)//�Z�J���h��Vector�ɎQ�ƃA�N�Z�X
		{
			std::string numStr;//�f�[�^�i�[����X�g�����O
			std::getline(dataStream, numStr, ',');//(���o���f�[�^�A���o�����f�[�^�̊i�[�A���o���L�[)

			data = atoi(numStr.c_str());
		}
		


		for (const auto& data : layer.first->second)
		{
			TRACE("%d", data);

		}
		TRACE("\n");
	}


	//�R���W�����̏���
	//auto collayer = map_node->first_node("objectgroup");
	//if (collayer == nullptr)
	//{
	//	TRACE("map�m�[�h��layer�m�[�h��objectgroup�m�[�h�̎擾�G���[\n");
	//	return false;
	//}
	//for (auto object = collayer->first_node(); object != nullptr; object = object->next_sibling())
	//{
	//	auto id = object->first_attribute("id")->value();
	//	double x = atoi(object->first_attribute("x")->value());
	//	double y = atoi(object->first_attribute("y")->value());
	//	//double width = atoi(object->first_attribute("width")->value());
	//	//double  height = atoi(object->first_attribute("height")->value());

	//	
	//	//colList_.push_back({ Vector2Dbl{x,y},Vector2Dbl{x + width, y + height} });//���㒸�_�A�E�㒸�_
	//	//colList_.push_back({ Vector2Dbl{x,y},Vector2Dbl{ width,  height} });
	//	//TRACE("id:%s,x:%d,y:%d,wid:%d,hei:%d\n", id, x, y, width, height);
	//}
	

	return true;
}

const Vector2& TmxObj::GetWoldArea(void)
{
	return worldArea_;
}

const Vector2& TmxObj::GetTileSize(void)
{
	return tileSize_;
}

const unsigned int TmxObj::GetLayerSize(void)
{
	return layerSize_;
}

const unsigned int TmxObj::GetFirstGID(void)
{
	return firstGID_;
}

const MapData& TmxObj::GetMapData(void)
{

	return mapData_;
}

const int TmxObj::GetMapData(std::string layer, Vector2 pos)
{
	auto chipPos = pos / tileSize_;
	return GetMapData(layer,chipPos.x_, chipPos.y_);//���W���}�X�ڐ��ɕϊ������̊֐��ɔC����
}

const int TmxObj::GetMapData(std::string layer, int x, int y)
{
	//at�͖������������ɍs��
	//try {
	//	
	//	if (point >= 0 && point < mapData_.at(layer).size())
	//	{
	//		return mapData_.at(layer)[point];
	//	}
	//}
	//catch (...)//���ɃG���[���w�肵�Ȃ��ꍇ
	//{
	//	//�G���[�̎��̏���
	//	return 0;
	//}


	if (mapData_.count(layer) == 0)//��̃��C���[�����Ȃ��悤�ɂ���
	{
		TRACE(" %s �͂���܂���\n", layer);
		return 0;
	}
	
	int point = worldArea_.x_ * y + x;

	if (0 <= point && point < mapData_[layer].size())
	{
		return mapData_[layer][point];
	}
	else
	{
		TRACE("%d�͂���܂���\n", point);
		return 0;
	}
	
}

const ColList& TmxObj::GetColList(void)
{
	return colList_;
}

bool TmxObj::ChackTiledVersion(rapidxml::xml_node<>* node)
{
	if (node == nullptr)
	{
		return false;
	}
	auto Version = node->first_attribute("tiledversion");//�擪�̃A�g���r���[�g���擾

	if (!virsion_.count(Version->value()))//�L�[�͑��݂��Ă��܂���
	{
		TRACE("Tiled�̔�Ή��o�[�W����\n");
		return false;
	}
	if (!virsion_[Version->value()])//���݂��Ȃ��ꍇ���̒l�ŐV�������L�[�͂����Ē��g�͂P�ł���
	{
		TRACE("Tiled�̔�Ή��o�[�W����\n");
		return false;
	}
	TRACE("Tiled�̑Ή��o�[�W����\n");

	return true;
}


