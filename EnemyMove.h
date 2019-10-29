#pragma once
#include<comoc\Vector2.h>

class EnemyMove
{
public:
	template<class T>
	EnemyMove(Vector2Template<T>& pos);
	~EnemyMove();
	void UpData(void);
private:
	template<class T>
	Vector2Template<T> & _pos;
};

