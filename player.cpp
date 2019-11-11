#include<DxLib.h>
#include "player.h"
#include"comon\ImageMng.h"
#include"Input\KeyState.h"

player::player()
{
	init();
}

player::player(Vector2db pos, Vector2db size)//
{
	_pos = pos;
	_size = size;
	init();
}

void player::Update(void)
{
	if (DestroyPrpc())
	{
		return;
	}
	
	(*_input).Updata();
	//_input->Updata();

	auto move = [](std::weak_ptr<InputState> keyDate, const INPUT_ID id, double& pNum, const double speed) {
		if (!keyDate.expired())
		{
			if ((*keyDate.lock()).state(id).first)
			{
				pNum += speed;
			}
		}
	};

	move(_input, INPUT_ID::LEFT,  _pos.x, -2);//
	move(_input, INPUT_ID::RIGHT, _pos.x, +2);
	//move(_input, INPUT_ID::RIGHT, _pos.x, 2.0);
	//move(_input, INPUT_ID::LEFT, _pos.x, -2.0);
	move(_input, INPUT_ID::UP,    _pos.y, -2);
	move(_input, INPUT_ID::DOWN,  _pos.y, +2);

}


player::~player()
{
}

void player::init(void)
{
	AnimVector data;

	data.emplace_back(lpImageMng.GetID("·¬×")[0], 30);
	data.emplace_back(lpImageMng.GetID("·¬×")[1], 60);
	SetAnim(STATE::NORMAL, data);

	/*data.reserve(1);
	data.emplace_back(lpImageMng.GetID("·¬×")[2], 60);
	SetAnim("EX", data);

	data.emplace_back(lpImageMng.GetID("PL”š”­")[0], 30);
	data.emplace_back(lpImageMng.GetID("PL”š”­")[1], 60);
	data.emplace_back(lpImageMng.GetID("PL”š”­")[2], 30);
	data.emplace_back(lpImageMng.GetID("PL”š”­")[3], 35);
	data.emplace_back(-1,40);
	SetAnim("DATH", data);*/

	_input = std::make_shared<KeyState>();
	//_input.reset(new KeyState());

	/*state("STATE::NORMAL");*/
}
