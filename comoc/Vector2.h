#pragma once

template<class T>class Vector2Template
{
public:
	Vector2Template();
	Vector2Template(T x, T y);
	~Vector2Template();
	T x;
	T y;
	
	//������Z�q
	Vector2Template& operator = (const Vector2Template& vec);

	//�P�����Z�q
	Vector2Template& operator += (const Vector2Template& vec);

	Vector2Template& operator -= (const Vector2Template& vec);
	
	Vector2Template& operator *= (T k);
	
	Vector2Template& operator /= (T k);

	Vector2Template operator + ()const;

	Vector2Template operator - ()const;
	
	//��r���Z�q
	bool operator == (const Vector2Template& vec)const;

	bool operator != (const Vector2Template& vec)const;

	bool operator > (const Vector2Template& vec)const;

	bool operator >= (const Vector2Template& vec)const;

	bool operator < (const Vector2Template& vec)const;

	bool operator <= (const Vector2Template& vec)const;

	//�Y�������Z�q
	T& operator [] (T i);
}; 

//�޸�ق̉��Z

// Vector2 + int
template<class T>
Vector2Template<T> operator +(const Vector2Template<T>& u, const T& k);

// Vector2 - int
template<class T>
Vector2Template<T> operator -(const Vector2Template<T>& u, const T& k);

// Vector2 * int
template<class T>
Vector2Template<T> operator *(const Vector2Template<T>& u, const T& k);

// int * Vector2
template<class T>
Vector2Template<T> operator *(const T& k, const Vector2Template<T>& u);

// Vector2 / int
template<class T>
Vector2Template<T> operator /(const Vector2Template<T>& u, const T& k);

// Vector2 % int
template<class T>
Vector2Template<T> operator %(const Vector2Template<T>& u, const T& k);

// Vector2 + Vector2
template<class T>
Vector2Template<T> operator +(const Vector2Template<T>& u,const Vector2Template<T>& v);

// Vector2 - Vector2
template<class T>
Vector2Template<T> operator -(const Vector2Template<T>& u, const Vector2Template<T>& v);

// Vector2 * Vector2
template<class T>
Vector2Template<T> operator *(const Vector2&Template<T> u, const Vector2Template<T>& v);

// Vector2 - Vector2
template<class T>
Vector2Template<T> operator /(const Vector2Template<T>& u, const Vector2Template<T>& v);

// Vector2 % Vector2
template<class T>
Vector2Template<T> operator %(const Vector2Template<T>& u, const Vector2Template<T>& v);

#include"details\Vector2.h"
