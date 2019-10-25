#pragma once
#include<Vector>
#include "BaseScene.h"
#include"Obj.h"

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	unique_Base Update(unique_Base own);
private:
	std::vector<sharedOdj> _objList ;
};

