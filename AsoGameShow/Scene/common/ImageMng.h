#pragma once
#include <vector>
#include <string>
#include <map>
#include "Vector2.h"


#define lpImageMng ImageMng::GetInstance()
using VecInt = std::vector<int>;

class ImageMng
{
public:
	static ImageMng& GetInstance()
	{
		static ImageMng s_Instance;
		return s_Instance;
	}
	
	const VecInt& GetID(std::string key);//key=パスが省いた　.pngを省略した物
	const VecInt& GetID(std::string f_name, std::string key, Vector2 divSize, Vector2 divCnt);
	const VecInt& GetID(std::string f_name, std::string key);
	
private:
	ImageMng();
	~ImageMng();
	std::map<std::string, VecInt> imageMap_;//string=key
protected:
};

