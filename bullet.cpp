#include "bullet.h"
#include"comon\ImageMng.h"
#include "Scene\SceneMag.h"



bullet::bullet()
{
}

bullet::bullet(UNIT_ID unitID, Vector2db pos)
{
	_unitID = unitID;
	zOrder = 0;
	_pos = pos;
	_size = { 3,8 };
	_rad = 270 * (3.141592 / 180);
	Init();
}

void bullet::Update(sharedOdj plObj)
{
	if (_dead)
	{
		return;
	}
	_pos.y += sin(_rad) * 3;
	_pos.x -= cos(_rad) * 3;
	if (_pos.y < -_size.y / 2 || _pos.y >(lpSceneMng.GameScreenSize.y + _size.y / 2))
	{
		SetAlive(false);
	}
}


bullet::~bullet()
{
}

int bullet::Init(void)
{
	return 0;
}

