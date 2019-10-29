#include "enemy.h"
#include"comoc\ImageMng.h"

enemy::enemy()
{
	init();
}

enemy::enemy(EnemyState a)
{
	_type = std::get<static_cast<int>(ENEMY_STATE::TYPE)>(a);
	_pos =
	_size =

	init();
}

void enemy::Update(void)
{
	if (DestroyPrpc())
	{
		return;
	}
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

	/*data.emplace_back(lpImageMng.GetID("“G”š”­")[0], 10);
	data.emplace_back(lpImageMng.GetID("“G”š”­")[1], 15);
	data.emplace_back(lpImageMng.GetID("“G”š”­")[2], 20);
	data.emplace_back(lpImageMng.GetID("“G”š”­")[3], 25);
	data.emplace_back(lpImageMng.GetID("“G”š”­")[4], 30);
	data.emplace_back(-1, 35);
	SetAnim("E_DATH", data); */

	/*state("STATE::NORMAL");*/
}
