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
	unique_Base Update(unique_Base own)override;			//更新
	~GameScene();
private:
	std::vector<sharedOdj> _objList ;						//ｵﾌﾞｼﾞｪｸﾄ用ﾘｽﾄ

	virtual void RunActQue(std::vector<ActQueT> actList);	//ｱｸｼｮﾝ用ｷｭｰ
};

