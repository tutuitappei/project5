#pragma once
#include<functional>
#include<Vector>
#include "BaseScene.h"
#include"Obj.h"

using funcAct = <()>;

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	unique_Base Update(unique_Base own)override;
private:
	std::vector<sharedOdj> _objList ;

	virtual void RunActQue(std::vector<ActQueT> actList);
};

