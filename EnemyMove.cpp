#include "EnemyMove.h"
#include"_debug\_DebugConOut.h"

EnemyMove::EnemyMove(Vector2db& pos):_pos(pos)//
{
	_move = nullptr;
	_aimCnt = -1;
}


EnemyMove::~EnemyMove()
{
}

void EnemyMove::UpData(void)
{
	if (_move != nullptr)
	{
		(this->*_move)();
	}
	//_pos.x++;//
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
	_endPos = _aim[_aimCnt].second;
	switch (_aim[_aimCnt].first)
	{
	case MOVE_TYPE::WAIT:
		_move = &EnemyMove::Wait;
		cnt = 0;
		break;
	case MOVE_TYPE::SIGMOID:
		_move = &EnemyMove::MoveSigmoid;
		break;
	case MOVE_TYPE::SPIRAL:
		_move = &EnemyMove::MoveSpiral;
		spr = abs(_endPos.x - _startPos.x);
		spRad = 0.0;
		spCnt = 0;
		break;
	case MOVE_TYPE::PITIN:
		_move = &EnemyMove::PitIn;
		break;
	case MOVE_TYPE::LR:
		_move = &EnemyMove::MoveLR;
		LRCnt = 0;
		break;
	default:
		AST();
		_move = &EnemyMove::Wait;
		break;
	}
}

void EnemyMove::MoveSigmoid(void)
{
	Vector2db _moveCnt = _startPos;
	
	if (_pos.x >= _endPos.x)
	{
		_pos = _endPos;
		SetMovePrg();
	}
	else
	{
		_pos.x = _moveCnt.x;
		_pos.y = (1.0/(1.0+exp(-_endPos.x)));
		_moveCnt.x++;
	}
}

void EnemyMove::MoveSpiral(void)
{
	if (spCnt >= 60*3)
	{
		SetMovePrg();
	}
	else
	{
		if (_startPos.y < _endPos.y)
		{
			(spRad--)+90.0;
		}
		if (_startPos.y > _endPos.y)
		{
			(spRad++)+90.0;
		}
		spr -= 0.5;
		spCnt++;
	}
	
}

void EnemyMove::PitIn(void)
{
	Vector2db _length;
	if (abs((_endPos-_startPos)/120.0) > abs(_endPos - _pos))//abs((_endPos-_startPos)/120.0)‚ðŠÖ”‰»
	{
		_pos = _endPos;
		_rad = 0.0;
		SetMovePrg();
	}
	else
	{
		_pos += (_endPos - _startPos) / 120.0;
		_length = _endPos - _pos;
		_rad = std::atan2(_length.y, _length.x) + (90 * 3.141592) / 180;
	}
}

void EnemyMove::Wait(void)
{
	cnt++;
	if (cnt >= _aim[_aimCnt].second.x)
	{
		SetMovePrg();
	}
}

void EnemyMove::MoveLR(void)
{
	if ()
	{
		_pos.x = LRCnt * ;
	}
	if()
	{
		SetMovePrg();
	}
	LRCnt++;
}
