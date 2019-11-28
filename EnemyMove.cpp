#include "EnemyMove.h"
#include<Scene\SceneMag.h>
#include"_debug\_DebugConOut.h"
#include"Obj.h"

EnemyMove::EnemyMove(Vector2db& pos):_pos(pos)//
{
	_move = nullptr;
	_aimCnt = -1;
	LRCnt = 0;
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

	LRCnt++;
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
	_checkPos.x = 0.0;
	_checkPos.y = 0.0;
	switch (_aim[_aimCnt].first)
	{
	case MOVE_TYPE::WAIT:
		_move = &EnemyMove::Wait;
		cnt = 0;
		break;
	//case MOVE_TYPE::SIGMOID:
	//	_move = &EnemyMove::MoveSigmoid;
	//	sigCnt = 0;
	//	break;
	case MOVE_TYPE::SPIRAL:
		_move = &EnemyMove::MoveSpiral;
		spr = 100;
		spRad = 0.0;
		spCnt = 0;
		break;
	case MOVE_TYPE::PITIN1:
		_move = &EnemyMove::PitIn;
		ptinCnt = 0;
		break;
	case MOVE_TYPE::LR:
		_move = &EnemyMove::MoveLR;
		break;
	case MOVE_TYPE::EXPAND:
		break;
	case MOVE_TYPE::ATTACK:
		break;
	case MOVE_TYPE::PITIN2:
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
	_checkPos = (_endPos - _pos);
	//ç∂
	if (_startPos.x < 0)
	{
		_pos.x++;
	}
	//âE
	else
	{
		_pos.x--;

	}

	_pos.y = ((1 / (1 + exp(-sigCnt)))*(_endPos.y - _startPos.y) + _startPos.y);
	sigCnt += 0.05;
	//TRACE("Y,%f\n", _pos.y);
	//TRACE("X,%f\n", _pos.x);
	_checkPos.y = abs(_checkPos.y);
	_checkPos.x = abs(_checkPos.x);
	if (_checkPos.y < 1 && _checkPos.x < 1)
	{
		_pos = _endPos;
		_rad = 0;
		SetMovePrg();
	}
}

void EnemyMove::MoveSpiral(void)
{
	_checkPos = (_endPos - _pos);

	if (_startPos.x > lpSceneMng.GameScreenSize.x / 2)
	{
		//ç∂â∫
		if (_startPos.y > lpSceneMng.GameScreenSize.y * 2 / 3)
		{
			spRad += 2 * 3.141592 / 180;
		}
		//ç∂è„
		else
		{
			spRad -= 2 * 3.141592 / 180;
		}
	}
	else
	{
		//âEâ∫
		if (_startPos.y > lpSceneMng.GameScreenSize.y * 2 / 3)
		{
			spRad -= 2 * 3.141592 / 180;
		}
		//âEè„
		else
		{
			spRad += 2 * 3.141592 / 180;
		}
	}




	_pos.x = _endPos.x + spr * sin(spRad);
	_pos.y = _endPos.y + spr * cos(spRad);

	//îºåaÇè¨Ç≥Ç≠Ç∑ÇÈ
	spr -= 0.5;

	//_rad = atan2(_checkPos.y, _checkPos.x) + 90.0*3.141592 / 180.0;
	_checkPos.y = abs(_checkPos.y);
	_checkPos.x = abs(_checkPos.x);
	if (_checkPos.y < 0.1 && _checkPos.x < 0.1)
	{
		_pos = _endPos;
		_rad = 0;
		SetMovePrg();
	}

}

void EnemyMove::PitIn(void)
{
	Vector2db _length;

	TRACE("%d\n", ptinCnt)

		ptinCnt++;

	if (abs((_endPos-_startPos)/120.0) > abs(_endPos - _pos))//abs((_endPos-_startPos)/120.0)Çä÷êîâª
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

	//if (_pos.y <= (lpSceneMng.GameScreenSize.y + 100.0))
	//{
	//	_pos.y = (lpSceneMng.GameScreenOffset.y - 100);
	//	_length = _endPos - _pos;
	//	_rad = std::atan2(_length.y, _length.x) + (90 * 3.141592) / 180;
	//}

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
	_pos.x = _pos.x + 1 * (((LRCnt / 100) % 2) * 2 - 1.0);
	_checkPos = (_endPos - _pos);
	_checkPos.y = abs(_checkPos.y);
	_checkPos.x = abs(_checkPos.x);
	/*SetMovePrg();*/
}

void EnemyMove::MoveExpand(void)
{
}

void EnemyMove::MoveAttack(void)
{

}
