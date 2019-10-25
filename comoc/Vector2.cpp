#include "Vector2.h"



Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y)
{
	Vector2::x = x;
	Vector2::y = y;
}

Vector2::~Vector2()
{
}

Vector2 & Vector2::operator=(const Vector2 & vec)
{
	// TODO: return ステートメントをここに挿入します
	x = vec.x;
	y = vec.y;

	return *this;
}

Vector2 & Vector2::operator+=(const Vector2 & vec)
{
	// TODO: return ステートメントをここに挿入します
	x += vec.x;
	y += vec.y;

	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 & vec)
{
	// TODO: return ステートメントをここに挿入します
	x -= vec.x;
	y -= vec.y;

	return *this;
}

Vector2 & Vector2::operator*=(int k)
{
	// TODO: return ステートメントをここに挿入します
	x *= k;
	y *= k;

	return *this;
}

Vector2 & Vector2::operator/=(int k)
{
	// TODO: return ステートメントをここに挿入します
	x /= k;
	y /= k;

	return *this;
}

Vector2 Vector2::operator+() const
{

	return *this;
}

Vector2 Vector2::operator-() const
{

	return Vector2(-this ->x,-this ->y);
}

bool Vector2::operator==(const Vector2 & vec) const
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
