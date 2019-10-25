#include<Dxlib.h>
#include "Obj.h"
#include<map>
#include"comoc\ImageMng.h"
#include"Scene\SceneMag.h"


Obj::Obj()
{
	_alive = true;
	_dead = false;
	_animFrame = 0;
	_animCnt = 0;
}

void Obj::Draw()
{
	if (_animMap.find(_state) == _animMap.end())
	{
		return;
	}
	if (_animFrame < 0 || _animFrame >= _animMap[_state].size())
	{
		return;
	}


	if (_animCnt >= _animMap[_state][_animFrame].second)
	{
		if (_animMap[_state][_animFrame].first >= 0)
		{
			_animFrame++;
		}
	}

	_animCnt++;

	if (_animFrame >= _animMap[_state].size())
	{
		_animFrame = 0;
		_animCnt = 0;
	}

	lpSceneMag.AddDrawQue({ _animMap[_state][_animFrame].first, _pos.x,_pos.y });
}

void Obj::Draw(int id)
{
	lpSceneMag.AddDrawQue({ id,_pos.x,_pos.y });

}

Obj::~Obj()
{
}

bool Obj::state(const STATE state)
{
	if (_animMap.find(state) == _animMap.end())
	{
		return false;
	}

	if (_state != state)
	{
		_animFrame = 0;
		_animCnt = 0;
	}

	_state = state;
	return true;
}

const STATE Obj::state(void) const
{
	return _state;
}

bool Obj::SetAnim(const STATE state, AnimVector& data)
{
	return (_animMap.try_emplace(state, std::move( data))).second;

	/*if (_animMap.find(key) == _animMap.end())
	{
		_animMap[key] = data;
		return true;
	}
	return false;*/
}

bool Obj::SetAlive(bool alive)
{
	_alive = alive;
	if (!_alive)
	{
		state(STATE::DETH);
	}
	return false;
}

bool Obj::isAnimEnd(void)
{
	if (_animMap.find(_state) == _animMap.end())
	{
		return true;
	}
	if (_animFrame < 0 || _animFrame >= _animMap[_state].size())
	{
		return true;
	}

	if (_animMap[_state][_animFrame].first < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

bool Obj::DestroyPrpc(void)
{
	if (_alive)
	{
		return false;
	}
	if (isAnimEnd())
	{
		_dead = true;
	}
	return true;
}
