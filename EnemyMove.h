#pragma once
#include<comoc\Vector2.h>

class EnemyMove
{
public:
	EnemyMove(Vector2& pos);
	~EnemyMove();
private:
	Vector2 & _pos;
};

