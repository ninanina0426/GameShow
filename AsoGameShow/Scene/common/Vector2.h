#pragma once


//template<class T> class �e���v���[�g�N���X��
template< class T> class Vector2template
{
public:
	Vector2template();
	Vector2template(T x, T y);
	~Vector2template();
	T x_;
	T y_;

	//������Z�q
	Vector2template& operator =(const Vector2template& vec);
	//�Y�������Z�q
	int& operator[](int i);
	//�P�����Z�q
	Vector2template& operator +=(const Vector2template& vec);
	Vector2template& operator -=(const Vector2template& vec);
	Vector2template& operator *=(const Vector2template& vec);
	Vector2template& operator /=(const Vector2template& vec);
	Vector2template& operator %=(const Vector2template& vec);
	Vector2template operator +()const;
	Vector2template operator -()const;

	//�񍀉��Z�q
	Vector2template operator + (Vector2template vec);
	Vector2template operator - (Vector2template vec);
	Vector2template operator / (Vector2template vec);
	Vector2template operator * (Vector2template vec);
	Vector2template operator % (Vector2template vec);

	//��r���Z�q

	bool operator == (const Vector2template& vec)const;
	bool operator != (const Vector2template& vec)const;
	bool operator <= (const Vector2template& vec)const;
	bool operator >= (const Vector2template& vec)const;
	bool operator > (const Vector2template& vec)const;
	bool operator < (const Vector2template& vec)const;
};
template<class T>
Vector2template<T> operator * (const Vector2template<T>& vec,T num);
template<class T>
Vector2template<T> operator * ( T num, const Vector2template<T>& vec);


using Vector2 = Vector2template<int>;
using Vector2Flt = Vector2template<float>;
using Vector2Dbl = Vector2template<double>;

#include "./details/Vector2.h"
