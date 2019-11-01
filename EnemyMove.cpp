#include "EnemyMove.h"
#include"_debug\_DebugConOut.h"

template<class T>
EnemyMove::EnemyMove(Vector2Template<double>& pos):_pos(pos)//
{
	_move = nullptr;
	_aimCnt = -1;
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
	if (newFlag)
	{
		_aim.clear();
	}
	_aim = std::move(state);
	if (newFlag)
	{
		SetMovePrg();
	}
	return false;
}

void EnemyMove::SetMovePrg(void)
{
	_aimCnt++;
	if (_aimCnt >= _aim.size())
	{
		return;
	}
	_startPos = _pos;
	_endPos = ;
	switch ()
	{
	case :
		break;
	case:
		break;
	case:
		break;
	case:
		break;
	default:
		AST();
		break;
	}
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
