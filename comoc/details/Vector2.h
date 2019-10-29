#include "Vector2.h"


template<class T>
Vector2Template<T>::Vector2Template()
{
	x = 0;
	y = 0;
}
template<class T>
Vector2Template<T>::Vector2Template(T x, T y)
{
	this->x = x;
	this->y = y;
}
template<class T>
Vector2Template<T>::~Vector2Template()
{
}
template<class T>
Vector2 & Vector2Template<T>::operator=(const Vector2Template<T> & vec)
{
	// TODO: return ステートメントをここに挿入します
	x = vec.x;
	y = vec.y;

	return *this;
}
template<class T>
Vector2 & Vector2Template<T>::operator+=(const Vector2Template<T> & vec)
{
	// TODO: return ステートメントをここに挿入します
	x += vec.x;
	y += vec.y;

	return *this;
}
template<class T>
Vector2 & Vector2Template<T>::operator-=(const Vector2Template<T> & vec)
{
	// TODO: return ステートメントをここに挿入します
	x -= vec.x;
	y -= vec.y;

	return *this;
}
template<class T>
Vector2 & Vector2Template<T>::operator*=(T k)
{
	// TODO: return ステートメントをここに挿入します
	x *= k;
	y *= k;

	return *this;
}
template<class T>
Vector2 & Vector2Template<T>::operator/=(T k)
{
	// TODO: return ステートメントをここに挿入します
	x /= k;
	y /= k;

	return *this;
}
template<class T>
Vector2 Vector2Template<T>::operator+() const
{

	return *this;
}
template<class T>
Vector2 Vector2Template<T>::operator-() const
{

	return Vector2(-this ->x,-this ->y);
}
template<class T>
bool Vector2Template<T>::operator==(const Vector2Template<T> & vec) const
{
	return ((this->x == vec.x) && (this->y == vec.y));
}

bool Vector2::operator!=(const Vector2 & vec) const
{
	return !((this->x == vec.x) && (this->y == vec.y));
}

bool Vector2::operator>(const Vector2 & vec) const
{
	return ((this->x > vec.x) && (this->y > vec.y));
}

bool Vector2::operator>=(const Vector2 & vec) const
{
	return ((this->x >= vec.x) && (this->y >= vec.y));
}

bool Vector2::operator<(const Vector2 & vec) const
{
	return ((this->x < vec.x) && (this->y < vec.y));
}

bool Vector2::operator<=(const Vector2 & vec) const
{
	return ((this->x <= vec.x) && (this->y <= vec.y));
}

int & Vector2::operator[](int i)
{
	// TODO: return ステートメントをここに挿入します
	if (i == 0)
	{
		return x;
	}
	else if (i == 1)
	{
		return y;
	}
	else
	{
		return x;
	}
}

Vector2 operator+(const Vector2 & u, const int & k)
{
	Vector2 vec;
	vec.x = u.x + k;
	vec.y = u.y + k;

	return vec;
}

Vector2 operator-(const Vector2 & u, const int & k)
{
	Vector2 vec;
	vec.x = u.x - k;
	vec.y = u.y - k;

	return vec;
}

Vector2 operator*(const Vector2 & u, const int & k)
{
	Vector2 vec;
	vec.x = u.x * k;
	vec.y = u.y * k;

	return vec;
}

Vector2 operator*(const int & k, const Vector2 & u)
{
	Vector2 vec;
	vec.x = k * u.x;
	vec.y = k * u.y;

	return vec;
}

Vector2 operator/(const Vector2 & u, const int & k)
{
	Vector2 vec;
	vec.x = u.x / k;
	vec.y = u.y / k;

	return vec;
}

Vector2 operator%(const Vector2 & u, const int & k)
{
	Vector2 vec;
	vec.x = u.x % k;
	vec.y = u.y % k;

	return vec;
}

Vector2 operator+(const Vector2 & u, const Vector2 & v)
{
	Vector2 vec;
	vec.x = u.x + v.x;
	vec.y = u.y + v.y;

	return vec;
}

Vector2 operator-(const Vector2 & u, const Vector2 & v)
{
	Vector2 vec;
	vec.x = u.x - v.x;
	vec.y = u.y - v.y;

	return vec;
}

Vector2 operator*(const Vector2 & u, const Vector2 & v)
{
	Vector2 vec;
	vec.x = u.x * v.x;
	vec.y = u.y * v.y;

	return vec;
}

Vector2 operator/(const Vector2 & u, const Vector2 & v)
{
	Vector2 vec;
	vec.x = u.x / v.x;
	vec.y = u.y / v.y;

	return vec;
}

Vector2 operator%(const Vector2 & u, const Vector2 & v)
{
	Vector2 vec;
	vec.x = u.x % v.x;
	vec.y = u.y % v.y;

	return vec;
}
