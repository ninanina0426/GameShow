#include <algorithm>
#include "Raycast.h"

bool Raycast::CheckCollision(Ray ray, Collision col)
{
	//��`�̎l�ӂ̃`�F�b�N
	//1�ł�����������A�E�g
	bool Flg = false;

	Line points[4]//�l��
	{
		{
			col.first,
			col.first + Vector2Dbl{col.second.x_,0.0}
		},
		{
			col.first + Vector2Dbl{col.second.x_,0.0},
			col.first + col.second
		},
		{
			col.first + col.second,
			col.first+Vector2Dbl{0.0,col.second.y_}
		},
		{
			col.first + Vector2Dbl{0.0,col.second.y_},
			col.first
		}

		//Vector2{col.first.x_,col.first.y_},//����
		//Vector2{col.second.x_,col.first.y_},//�E��
		//Vector2{col.second.x_,col.second.y_},//�E��
		//Vector2{col.first.x_,col.second.y_}//����
		//
		//Vector2{col.second.x_,col.first.y_} - Vector2{col.first.x_,col.first.y_},//���
		//Vector2{col.second.x_,col.second.y_} - Vector2{col.second.x_,col.first.y_},//�E��
		//Vector2{col.second.x_,col.second.y_} - Vector2{col.first.x_,col.second.y_},//����
		//Vector2{col.first.x_,col.second.y_} - Vector2{col.first.x_,col.first.y_}//����
	};
	for (auto point : points)
	{
		Flg |= CheckRay(ray, point);//��ł�����������true
	}
	

	return Flg;
}

bool Raycast::CheckRay(Ray ray, Line line)
{
	//bool Flag = false;
	//�������������Ă��邩
	//	0�Ȃ畽�s�Ȃ̂Ōv�Z���Ȃ�
	/*auto raypos = ray.point + ray.vec;
	auto ULine = line.end[1] - line.point[0];
	auto DLine = line.end[2] - line.point[3];
	auto RLine = line.end[2] - line.point[1];
	auto LLine = line.end[3] - line.point[0];
	
	acos(raypos.x_* line.point[0] - raypos.y_ * line.end[0]);*/




	auto checkCross = [](Vector2Dbl& vec1, Vector2Dbl& vec2) {
		return ((vec1.x_ * vec2.y_) - (vec2.x_ * vec1.y_));
	};

	Vector2Dbl& vecRay = ray.vec;
	Vector2Dbl&& vecLine = line.end - line.point;

	double crossRayLine=checkCross(vecRay, vecLine);
	//���s��������
	if (crossRayLine==0)
	{
		return false;
	}
	Vector2Dbl v = Vector2Dbl{ line.point.x_ - ray.point.x_,line.point.y_ - ray.point.y_ };
	double cross_vRay = checkCross(v, vecRay);
	double cross_vLine = checkCross(v, vecLine);

	float ans1 = cross_vRay / crossRayLine;
	float ans2 = cross_vLine / crossRayLine;
	if (ans1 > 0.0f && ans1 <= 1.0f &&
		ans2 > 0.0f && ans2 <= 1.0f)
	{
		return true;
	}
	
	return false;
}
