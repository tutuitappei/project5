#pragma once

template<class T>class Vector2Template
{
public:
	Vector2Template();
	Vector2Template(T x, T y);
	~Vector2Template();
	int x;
	int y;
	
	//‘ã“ü‰‰ŽZŽq
	Vector2Template& operator = (const Vector2Template& vec);

	//’P€‰‰ŽZŽq
	Vector2Template& operator += (const Vector2Template& vec);

	Vector2Template& operator -= (const Vector2Template& vec);
	
	Vector2Template& operator *= (T k);
	
	Vector2Template& operator /= (T k);

	Vector2Template operator + ()const;

	Vector2Template operator - ()const;
	
	//”äŠr‰‰ŽZŽq
	bool operator == (const Vector2Template& vec)const;

	bool operator != (const Vector2Template& vec)const;

	bool operator > (const Vector2Template& vec)const;

	bool operator >= (const Vector2Template& vec)const;

	bool operator < (const Vector2Template& vec)const;

	bool operator <= (const Vector2Template& vec)const;

	//“Y‚¦Žš‰‰ŽZŽq
	int& operator [] (T i);
}; 

//ÍÞ¸ÄÙ‚Ì‰‰ŽZ

// Vector2 + int
Vector2 operator +(const Vector2& u, const int& k);

// Vector2 - int
Vector2 operator -(const Vector2& u, const int& k);

// Vector2 * int
Vector2 operator *(const Vector2& u, const int& k);

// int * Vector2
Vector2 operator *(const int& k, const Vector2& u);

// Vector2 / int
Vector2 operator /(const Vector2& u, const int& k);

// Vector2 % int
Vector2 operator %(const Vector2& u, const int& k);

// Vector2 + Vector2
Vector2 operator +(const Vector2& u,const Vector2& v);

// Vector2 - Vector2
Vector2 operator -(const Vector2& u, const Vector2& v);

// Vector2 * Vector2
Vector2 operator *(const Vector2& u, const Vector2& v);

// Vector2 - Vector2
Vector2 operator /(const Vector2& u, const Vector2& v);

// Vector2 % Vector2
Vector2 operator %(const Vector2& u, const Vector2& v);

#include"details\Vector2.h"
