#include<DxLib.h>
#include "BaseScene.h"
#include"SceneMag.h"
#include<comon\ImageMng.h>



BaseScene::BaseScene()
{
	MakeScreen(lpSceneMng.ScreenSize.x, lpSceneMng.ScreenSize.y,true);
}


BaseScene::~BaseScene()
{
}

void BaseScene::FeadInit(std::string fadtyp)
{
}

bool BaseScene::FeadUpdate(void)
{
	return false;
}

