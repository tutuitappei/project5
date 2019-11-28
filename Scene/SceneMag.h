#pragma once
#include<memory>
#include<tuple> 
#include<vector>
#include<map>
#include <comon/Vector2.h>
#include"BaseScene.h"

#define lpSceneMng SceneMag::GetInstance()

enum class DRAW_QUE	//enum claseがあることで同じものでも別の型として扱える　安全性あり
{
	IMAGE,
	X,
	Y,
	RAD,
	ZORDER,  //ﾚｲﾔｰ内の描画順(数値の低いほうが奥)
	LAYER	//優先度描画順(奥から)
};
enum class LAYER
{
	BG,
	//UI,
	CHAR,
	UI,
	MAX
};

//別に作る
LAYER begin(LAYER);
LAYER end(LAYER);
LAYER operator *(LAYER key);
LAYER operator ++(LAYER& key);

using DrawQueT = std::tuple<int, double, double, double, int, LAYER>;//

class SceneMag
{
public:
	static SceneMag &GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SceneMag();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	};

	void Run(void);

	bool AddDrawQue(DrawQueT dQue);//
	bool AddActQue(ActQueT aQue);

	const Vector2in ScreenSize;
	const Vector2in ScreenCenter;
	const Vector2in GameScreenSize;
	const Vector2in GameScreenOffset;
	int 	gameCnt;
private:
	static SceneMag *sInstance;

	unique_Base _activeScene;

	void Draw(void);


	std::map<LAYER,int>_screenID;

	
	std::vector<ActQueT> _actList;
	std::vector< DrawQueT> _drawList;

	SceneMag();
	~SceneMag();
	bool SysInit(void);
};

