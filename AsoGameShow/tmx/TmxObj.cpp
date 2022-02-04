#include <sstream>
#include "TmxObj.h"
#include "../Scene/common/ImageMng.h"
#include "../_debug/_DebugConOut.h"

TmxObj::TmxObj()
{
	//対応しているバージョンを格納する
	virsion_["1.7.2"] = 1;
	
}

TmxObj::~TmxObj()
{
}

bool TmxObj::LoadTSX(std::string fileName)
{
	rapidxml::file<> xmlFileName = fileName.c_str();//データを格納
	tsxDoc_.parse<0>(xmlFileName.data());

	rapidxml::xml_node<>* tileset = tsxDoc_.first_node("tileset");//先頭のノードを取得する
	//auto tiledversion = tileset->first_attribute("tiledversion");//先頭のアトリビュートを取得

	//バージョンチェック
	if (!ChackTiledVersion(tileset))
	{
		return false;
	}
	
	//一番初めのノードを拾ってくる
	auto node = tsxDoc_.first_node();
	
	
	while (node)//中身がないとnullptrが返ってくる
	{
		if (node->name_size())//名前の文字列長取得
		{
			//デバッグ用
			TRACE("%s→", node->name());
		}
		//親のノードを探す
		auto atr = node->first_attribute();
		
		while (atr)
		{
			if (atr->name_size())
			{
				//名前の取得
				TRACE("%s:", atr->name());
			}
			//中身の取得
			TRACE("%s ", atr->value());
			//次のアトリビュートへ
			atr=atr->next_attribute();
		}
		TRACE("\n");
		//次のノードへ
		node = node->next_sibling();
	}
	
	/*auto tileID = tileset->first_node("tile");
	auto image = tileID->first_node("image");*/
	auto image = tileset->first_node("image");
	std::string source=image->first_attribute("source")->value();//ファイル名
	auto keyName = source.substr(source.find_last_of("/")+1);//substr=特定の位置の情報を取得
	auto tilieWide = atoi(tileset->first_attribute("tilewidth")->value());//atoi=int型に変換チップの横サイズ
	auto tilieHeigt = atoi(tileset->first_attribute("tileheight")->value());
	auto tiledivX = atoi(tileset->first_attribute("columns")->value());//横の総チップ数
	auto tiledivY = atoi(tileset->first_attribute("tilecount")->value()) / tiledivX;//タイルの総チップ数/横の総数

	lpImageMng.GetID(source, keyName, Vector2{ tilieWide ,tilieHeigt }, Vector2{ tiledivX,tiledivY});


	return true;
}

bool TmxObj::LoadTMX(std::string fileName)
{
	
	rapidxml::file<> xmlFileName = fileName.c_str();//ファイル読み込みデータを格納
	tmxDoc_.parse<0>(xmlFileName.data());
	
	rapidxml::xml_node<>* map_node = tmxDoc_.first_node("map");//先頭のノードを取得する

	//ファイルのバージョンチェック
	if (!ChackTiledVersion(map_node))
	{
		return false;
	}
	
	auto tileset= map_node->first_node("tileset");
	
	
	auto pass = fileName.substr(0,fileName.find_last_of("/") + 1);//substr=特定の位置の情報を取得
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
	rapidxml::xml_node<>* map_node = tmxDoc_.first_node("map");//ここにバージョン確認をしてもいい
	if (map_node == nullptr)
	{
		TRACE("mapのノード取得エラー\n");
		return false;
	}
	//layerの取得処理
	for (auto layernode = map_node->first_node("layer"); layernode != nullptr; layernode = layernode->next_sibling())
	{
		if (layernode == nullptr)
		{
			TRACE("mapノード→layerノードの取得エラー\n");
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
		
		auto layerData = layernode->first_node("data")->first_node();//csv形式のデータが入っている

		std::stringstream dataStream;
		dataStream << layerData->value();

		for (auto& data : layer.first->second)//セカンドのVectorに参照アクセス
		{
			std::string numStr;//データ格納するストリング
			std::getline(dataStream, numStr, ',');//(取り出すデータ、取り出したデータの格納、取り出すキー)

			data = atoi(numStr.c_str());
		}
		


		for (const auto& data : layer.first->second)
		{
			TRACE("%d", data);

		}
		TRACE("\n");
	}


	//コリジョンの処理
	//auto collayer = map_node->first_node("objectgroup");
	//if (collayer == nullptr)
	//{
	//	TRACE("mapノード→layerノード→objectgroupノードの取得エラー\n");
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
	//	//colList_.push_back({ Vector2Dbl{x,y},Vector2Dbl{x + width, y + height} });//左上頂点、右上頂点
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
	return GetMapData(layer,chipPos.x_, chipPos.y_);//座標をマス目数に変換し下の関数に任せる
}

const int TmxObj::GetMapData(std::string layer, int x, int y)
{
	//atは無理やり情報を見に行く
	//try {
	//	
	//	if (point >= 0 && point < mapData_.at(layer).size())
	//	{
	//		return mapData_.at(layer)[point];
	//	}
	//}
	//catch (...)//特にエラーを指定しない場合
	//{
	//	//エラーの時の処理
	//	return 0;
	//}


	if (mapData_.count(layer) == 0)//空のレイヤーを作らないようにする
	{
		TRACE(" %s はありません\n", layer);
		return 0;
	}
	
	int point = worldArea_.x_ * y + x;

	if (0 <= point && point < mapData_[layer].size())
	{
		return mapData_[layer][point];
	}
	else
	{
		TRACE("%dはありません\n", point);
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
	auto Version = node->first_attribute("tiledversion");//先頭のアトリビュートを取得

	if (!virsion_.count(Version->value()))//キーは存在していますか
	{
		TRACE("Tiledの非対応バージョン\n");
		return false;
	}
	if (!virsion_[Version->value()])//存在しない場合その値で新しく作るキーはあって中身は１ですか
	{
		TRACE("Tiledの非対応バージョン\n");
		return false;
	}
	TRACE("Tiledの対応バージョン\n");

	return true;
}


