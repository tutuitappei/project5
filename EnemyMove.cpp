#include "EnemyMove.h"

template<class T>
EnemyMove::EnemyMove(Vector2Template<double>& pos):_pos(pos)//
{
	_move = nullptr;
}


EnemyMove::~EnemyMove()
{
}
template<class T>
void EnemyMove::UpData(void)
{
	_pos.x++;//
}

bool EnemyMove::SetMoveState(MoveState & state, bool newFlag)
{
	if (newFlag == true)
	{
		
	}

	return false;
}

void EnemyMove::MoveSigmoid(void)
{
}

void EnemyMove::MoveSpiral(void)
{
}

void EnemyMove::PitIn(void)
{
}

void EnemyMove::Wait(void)
{
}

void EnemyMove::MoveLR(void)
{
}
