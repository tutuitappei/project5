#include "EnemyMove.h"


template<class T>
EnemyMove::EnemyMove(Vector2Template<T>& pos):_pos(pos)
{
	
}


EnemyMove::~EnemyMove()
{
}
template<class T>
void EnemyMove::UpData(void)
{
	_pos.x++;
}
