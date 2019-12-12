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
	virtual unique_Base Update(unique_Base own) = 0;		//çXêV
protected:
	void FeadInit(std::string fadtyp);
	bool FeadUpdate(void);
private:
	int _fadeCnt;
	std::string _fadtyp;
};

