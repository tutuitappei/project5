//#include "Vector2.h"


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
	this->x = vec.x;
	this->y = vec.y;

	return *this;
}
template<class T>
Vector2 & Vector2Template<T>::operator+=(const Vector2Template<T> & vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}
template<class T>
Vector2 & Vector2Template<T>::operator-=(const Vector2Template<T> & vec)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}
template<class T>
Vector2 & Vector2Template<T>::operator*=(T k)
{
	this->x *= k;
	this->y *= k;

	return *this;
}
template<class T>
Vector2 & Vector2Template<T>::operator/=(T k)
{
	this->x /= k;
	this->y /= k;

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
template<class T>
bool Vector2Template<T>::operator!=(const Vector2Template<T> & vec) const
{
	return !((this->x == vec.x) && (this->y == vec.y));
}
template<class T>
bool Vector2Template<T>::operator>(const Vector2Template<T> & vec) const
{
	return ((this->x > vec.x) && (this->y > vec.y));
}
template<class T>
bool Vector2Template<T>::operator>=(const Vector2Template<T> & vec) const
{
	return ((this->x >= vec.x) && (this->y >= vec.y));
}
template<class T>
bool Vector2Template<T>::operator<(const Vector2Template<T> & vec) const
{
	return ((this->x < vec.x) && (this->y < vec.y));
}
template<class T>
bool Vector2Template<T>::operator<=(const Vector2Template<T> & vec) const
{
	return ((this->x <= vec.x) && (this->y <= vec.y));
}
template<class T>
T & Vector2Template<T>::operator[](T i)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
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
template<class T>
Vector2 operator+(const Vector2Template<T> & u, const T & k)
{
	Vector2 vec;
	vec.x = u.x + k;
	vec.y = u.y + k;

	return vec;
}
template<class T>
Vector2Template<T> operator-(const Vector2Template<T> & u, const T & k)
{
	Vector2 vec;
	vec.x = u.x - k;
	vec.y = u.y - k;

	return vec;
}
template<class T>
Vector2Template<T> operator*(const Vector2Template<T> & u, const T & k)
{
	Vector2 vec;
	vec.x = u.x * k;
	vec.y = u.y * k;

	return vec;
}
template<class T>
Vector2Template<T> operator*(const T & k, const Vector2Template<T> & u)
{
	Vector2 vec;
	vec.x = k * u.x;
	vec.y = k * u.y;

	return vec;
}
template<class T>
Vector2Template<T> operator/(const Vector2Template<T> & u, const T & k)
{
	Vector2 vec;
	vec.x = u.x / k;
	vec.y = u.y / k;

	return vec;
}
template<class T>
Vector2Template<T> operator%(const Vector2Template<T> & u, const T & k)
{
	Vector2 vec;
	vec.x = u.x % k;
	vec.y = u.y % k;

	return vec;
}
template<class T>
Vector2Template<T> operator+(const Vector2Template<T> & u, const Vector2Template<T>2 & v)
{
	Vector2 vec;
	vec.x = u.x + v.x;
	vec.y = u.y + v.y;

	return vec;
}
template<class T>
Vector2Template<T> operator-(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	Vector2 vec;
	vec.x = u.x - v.x;
	vec.y = u.y - v.y;

	return vec;
}
template<class T>
Vector2Template<T> operator*(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	Vector2 vec;
	vec.x = u.x * v.x;
	vec.y = u.y * v.y;

	return vec;
}
template<class T>
Vector2Template<T> operator/(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	Vector2 vec;
	vec.x = u.x / v.x;
	vec.y = u.y / v.y;

	return vec;
}
template<class T>
Vector2Template<T> operator%(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	Vector2 vec;
	vec.x = u.x % v.x;
	vec.y = u.y % v.y;

	return vec;
}