#include "Title.h"
#include"GameScene.h"
#include<Dxlib.h>


Title::Title()
{
}


Title::~Title()
{
}

unique_Base Title::Update(unique_Base own)
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::make_unique<GameScene>();
	}
	return std::move(own);
}

