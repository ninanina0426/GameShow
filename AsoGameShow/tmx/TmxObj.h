#pragma once
#include <string>
#include <map>
#include <vector>
#include <list>
#include "../Scene/common/Vector2.h"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "../Scene/common/ImageMng.h"
#include "../Scene/common/collision.h"


using MapData = std::map<std::string, std::vector<int>>;//���C���[�����L�[

class TmxObj
{
public:
	TmxObj();
	~TmxObj();
	bool LoadTSX(std::string fileName);//Tsx�̃��[�h
	bool LoadTMX(std::string fileName);//Tmx�̃��[�h
	bool LoadXml(std::string fileName);
	bool SetMap(void);

	const Vector2& GetWoldArea(void);//
	const Vector2& GetTileSize(void);//
	const unsigned int GetLayerSize(void);//
	const unsigned int GetFirstGID(void);//

	const MapData& GetMapData(void);//
	const int GetMapData(std::string layer, Vector2 pos);//pos�͍��W�ϊ�
	const int GetMapData(std::string layer, int x, int y);//x�Ay�̓}�X�ڐ�

	const ColList& GetColList(void);
private:
	bool ChackTiledVersion(rapidxml::xml_node<>* node);
	std::map<std::string, int> virsion_;//�o�[�W�����Ǘ�<�L�[�A�f�[�^��

	//TMX
	rapidxml::xml_document<> tmxDoc_;
	unsigned int firstGID_;
	unsigned int layerSize_;
	Vector2 worldArea_;
	Vector2 tileSize_;

	MapData  mapData_;

	ColList colList_;
	//TSX
	rapidxml::xml_document<> tsxDoc_;//tsx�̃h�L�������g���i�[


};

