#include "EnemyMove.h"
#include<Scene\SceneMag.h>
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
	if (_aimCnt >= static_cast<signed>(_aim.size()))
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
		sigCnt = 0;
		break;
	case MOVE_TYPE::SPIRAL:
		_move = &EnemyMove::MoveSpiral;
		spr = abs(_endPos.x - _startPos.x);
		spRad = 0.0;
		spCnt = 0;
		break;
	case MOVE_TYPE::PITIN1:
		_move = &EnemyMove::PitIn;
		break;
	case MOVE_TYPE::LR:
		_move = &EnemyMove::MoveLR;
		/*LRCnt = 0;*/
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
	Vector2Template<double> checkPos = (_endPos - _pos);
	//左
	if (_startPos.x < 0)
	{
		_pos.x++;
	}
	//右
	else
	{
		_pos.x--;

	}

	_pos.y = ((1 / (1 + exp(-sigCnt)))*(_endPos.y - _startPos.y) + _startPos.y);
	sigCnt += 0.05;
	//TRACE("Y,%f\n", _pos.y);
	//TRACE("X,%f\n", _pos.x);
	checkPos.y = abs(checkPos.y);
	checkPos.x = abs(checkPos.x);
	if (checkPos.y < 1 && checkPos.x < 1)
	{
		_pos = _endPos;
		_rad = 0;
		SetMovePrg();
	}
}

void EnemyMove::MoveSpiral(void)
{
	Vector2Template<double> checkPos = (_endPos - _pos);

	if (_startPos.x > lpSceneMng.GameScreenSize.x / 2)
	{
		//左下
		if (_startPos.y > lpSceneMng.GameScreenSize.y * 2 / 3)
		{
			spRad += 2 * 3.141592 / 180;
		}
		//左上
		else
		{
			spRad -= 2 * 3.141592 / 180;
		}
	}
	else
	{
		//右下
		if (_startPos.y > lpSceneMng.GameScreenSize.y * 2 / 3)
		{
			spRad -= 2 * 3.141592 / 180;
		}
		//右上
		else
		{
			spRad += 2 * 3.141592 / 180;
		}
	}




	_pos.x = _endPos.x + spr * sin(spRad);
	_pos.y = _endPos.y + spr * cos(spRad);

	//半径を小さくする
	spr -= 0.4;

	//_rad = atan2(checkPos.y, checkPos.x) + 90.0*3.141592 / 180.0;
	checkPos.y = abs(checkPos.y);
	checkPos.x = abs(checkPos.x);
	if (checkPos.y < 0.1 && checkPos.x < 0.1)
	{
		_pos = _endPos;
		_rad = 0;
		SetMovePrg();
	}
}

void EnemyMove::PitIn(void)
{
	Vector2db _length;
	if (abs((_endPos-_startPos)/120.0) > abs(_endPos - _pos))//abs((_endPos-_startPos)/120.0)を関数化
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
	if (cnt >= _endPos.x)
	{
		SetMovePrg();
	}
	cnt++;
}

void EnemyMove::MoveLR(void)
{
	//if ()
	//{
	//	_pos.x = LRCnt * ;
	//}
	//if()
	//{
	//	SetMovePrg();
	//}
	//LRCnt++;
}

void EnemyMove::MoveExpand(void)
{
}

void EnemyMove::MoveAttack(void)
{

}
