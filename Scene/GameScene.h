#pragma once
#include<functional>
#include<Vector>
#include "BaseScene.h"
#include"Obj.h"

using funcAct = std::function<bool()>;

class GameScene :
	public BaseScene
{
public:
	GameScene();
	unique_Base Update(unique_Base own)override;			//�X�V
	~GameScene();
private:
	std::vector<sharedOdj> _objList ;						//��޼ު�ėpؽ�

	virtual void RunActQue(std::vector<ActQueT> actList);	//����ݗp���
};

