#pragma once
#include "Vector2.h"
#include "collision.h"
class Raycast
{
public:
	struct Ray
	{
		Vector2Dbl point;//始点
		Vector2Dbl vec;//方向ベクトル
	};

	struct Line
	{
		Vector2Dbl point;//始点
		Vector2Dbl end;//終点
		//Vector2 vec() { return end - point; };//方向ベクトル
	};
	bool CheckCollision(Ray ray, Collision col);
	bool CheckRay(Ray ray, Line line);

private:

};

