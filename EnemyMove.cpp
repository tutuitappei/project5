#include "EnemyMove.h"
#include<Scene\SceneMag.h>
#include"_debug\_DebugConOut.h"
#include"Obj.h"

int EnemyMove::enemyCnt;

EnemyMove::EnemyMove(Vector2Template<double>& pos, double& rad) :_pos(pos), _rad(rad)
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
	_checkPos.x = 0.0;
	_checkPos.y = 0.0;
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
		spr = 65;
		spRad = 0.0;
		spCnt = 0;
		break;
	case MOVE_TYPE::PITIN1:
		_move = &EnemyMove::PitIn;
		ptinCnt = 0;
		_endPos.x = (_endPos.x - 45 + ((((lpSceneMng.gameCnt + 120) / 100) % 2) * 100)) + ((lpSceneMng.gameCnt + 120) % 100)*((((lpSceneMng.gameCnt + 120) / 100) % 2) * -2 + 1.0);
		break;
	case MOVE_TYPE::LR:
		enemyCnt = enemyCnt + 1;
		moveCnt = 0.0;
		_move = &EnemyMove::MoveLR;
		break;
	case MOVE_TYPE::EXPAND:
		_move = &EnemyMove::MoveExpand;
		break;
	case MOVE_TYPE::ATTACK:
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
	if (_startPos.x <= 0)
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
	_rad = std::atan2(_pos.y - _oldPos.y, _pos.x - _oldPos.x) + 90.0*3.141592 / 180;
	_checkPos.y = abs(_checkPos.y);
	_checkPos.x = abs(_checkPos.x);
	if (_checkPos.y < 1 && _checkPos.x < 1)
	{
		_pos = _endPos;
		_rad = 0;
		SetMovePrg();
	}
	_oldPos = _pos;
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

	spr -= 0.2;

	_rad = std::atan2(_pos.y - _oldPos.y, _pos.x - _oldPos.x) + 90.0*3.141592 / 180;
	_checkPos.y = abs(_checkPos.y);
	_checkPos.x = abs(_checkPos.x);
	if (_checkPos.y < 0.1 && _checkPos.x < 0.1)
	{
		_pos = _endPos;
		_rad = 0;
		SetMovePrg();
	}
	_oldPos = _pos;
}

void EnemyMove::PitIn(void)
{
	Vector2db _length;
	_length = (_endPos - _pos);

	if (abs((_endPos-_startPos)/120.0) > abs(_endPos - _pos))
	{
		_pos.y = _endPos.y;
		_pos.x = _endPos.x;
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
	_pos.x = (_endPos.x - 45 + (((lpSceneMng.gameCnt / 100) % 2)*100))+ (lpSceneMng.gameCnt % 100)*(((lpSceneMng.gameCnt / 100) % 2) * -2 + 1.0);
	if (enemyCnt >= 50)
	{
		//if (moveCnt >= 52)
		//{
			SetMovePrg();
		//}
		moveCnt++;
	}

}

void EnemyMove::MoveExpand(void)
{
	_pos.x += ((_aim[_aimCnt].second.x - static_cast<double>(lpSceneMng.GameScreenSize.x / 2))*(((lpSceneMng.gameCnt / 30) % 2) * 2.0 - 1.0)) / 100.0;
	_pos.y += ((_aim[_aimCnt].second.y )*(((lpSceneMng.gameCnt / 30) % 2) * 2.0 - 1.0)) / 100.0;
}

void EnemyMove::MoveAttack(void)
{

}
