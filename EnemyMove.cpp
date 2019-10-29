#include "EnemyMove.h"



EnemyMove::EnemyMove(Vector2& pos):_pos(pos)
{
	
}


EnemyMove::~EnemyMove()
{
}

void EnemyMove::UpData(void)
{
	_pos.x++;
}
