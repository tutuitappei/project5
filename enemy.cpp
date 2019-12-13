#include "enemy.h"
#include"comon\ImageMng.h"

enemy::enemy()
{
	init();
}

enemy::enemy(EnemyState& a)
{
	_type = std::get<static_cast<int> (ENEMY_STATE::TYPE)>(a);
	_pos = std::move(std::get<static_cast<int> (ENEMY_STATE::VECTOR)>(a));
	_size = std::move(std::get<static_cast<int> (ENEMY_STATE::SIZE)>(a));

	_moveCtl.SetMoveState(std::get<static_cast<int>(ENEMY_STATE::AIM)>(a),true);

	init();
}

void enemy::Update(sharedOdj plObj)
{
	if (DestroyPrpc())
	{
		return;
	}
	_moveCtl.UpData();
}


enemy::~enemy()
{
}

void enemy::init(void)
{
	AnimVector data;

	data.emplace_back(lpImageMng.GetID("·¬×")[10], 30);
	data.emplace_back(lpImageMng.GetID("·¬×")[11], 60);
	SetAnim(STATE::NORMAL, data);
	//data.emplace_back(IMAGE_ID("·¬×")[10 + (2 * static_cast<int>(_Type))], 30);
	//data.emplace_back(IMAGE_ID("·¬×")[1 + 10 + (2 * static_cast<int>(_Type))], 60);
	//SetAnim(STATE::NORMAL, data);

	data.emplace_back(IMAGE_ID("“G”š”­")[0], 10);
	data.emplace_back(IMAGE_ID("“G”š”­")[1], 15);
	data.emplace_back(IMAGE_ID("“G”š”­")[2], 20);
	data.emplace_back(IMAGE_ID("“G”š”­")[3], 25);
	data.emplace_back(IMAGE_ID("“G”š”­")[4], 35);
	data.emplace_back(-1, 40);
	SetAnim(STATE::DETH, data);

	state(STATE::NORMAL);
}

