#include <DxLib.h>
#include "ImageMng.h"
#include "../../_debug/_DebugConOut.h"

const VecInt& ImageMng::GetID(std::string key)
{
	GetID(key, key);
	//if (imageMap_.count(key) == 0)
	//{
	//	//読み込んでいない場合
	//	imageMap_[key].resize(1);//VecIntのサイズを確定させる
	//	imageMap_[key][0] = LoadGraph(key.c_str());//VecIntなので配列の先頭に読み込む
	//}
	return imageMap_[key];//画像を返す
	
}

const VecInt& ImageMng::GetID(std::string f_name, std::string key, Vector2 divSize, Vector2 divCnt)
{
	if (imageMap_.count(key) == 0)
	{
		//読み込んでいない場合
		imageMap_[key].resize(divCnt.x_ * divCnt.y_);//static_cast<UINT64>を書くと治る 型あふれをしている為波線
		if (LoadDivGraph(
			f_name.c_str(),
			divCnt.x_ * divCnt.y_,
			divCnt.x_, divCnt.y_,
			divSize.x_, divSize.y_,
			&imageMap_[key][0],
			true) == -1)
		{
			TRACE("画像読み込み失敗：%s\n", f_name.c_str());
		}
	}
	return imageMap_[key];
}

const VecInt& ImageMng::GetID(std::string f_name, std::string key)
{
	if (imageMap_.count(key) == 0)
	{
		//読み込んでいない場合
		imageMap_[key].resize(1);//VecIntのサイズを確定させる
		imageMap_[key][0] = LoadGraph(f_name.c_str());//VecIntなので配列の先頭に読み込む
	}
	return imageMap_[key];//画像を返す
}

ImageMng::ImageMng()
{
}

ImageMng::~ImageMng()
{
}
