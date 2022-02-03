#pragma once
#include "Vector2.h"
#include "collision.h"
class Raycast
{
public:
	struct Ray
	{
		Vector2Dbl point;//�n�_
		Vector2Dbl vec;//�����x�N�g��
	};

	struct Line
	{
		Vector2Dbl point;//�n�_
		Vector2Dbl end;//�I�_
		//Vector2 vec() { return end - point; };//�����x�N�g��
	};
	bool CheckCollision(Ray ray, Collision col);
	bool CheckRay(Ray ray, Line line);

private:

};

