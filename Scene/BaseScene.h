#pragma once
#include<memory>
#include<Obj.h>
#include<vector>

class BaseScene;

enum class ACT_QUE
{
	NON,
	SHOT
};


using unique_Base = std::unique_ptr<BaseScene>;
using ActQueT = std::pair<ACT_QUE, Obj&>;

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual unique_Base Update(unique_Base own) = 0;
	virtual void RunActQue(std::vector<ActQueT> actList);
};

