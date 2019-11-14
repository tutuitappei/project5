#pragma once
#include<memory>
#include<tuple>  //3つ以上の違う型の要素を取り扱う(2つの時はpair)
#include<vector>
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
	LAYER	//描画順(奥から)
};
enum class LAYER
{
	BG,
	CHAR,
	UI
};

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

	const Vector2in ScreenSize;
private:
	static SceneMag *sInstance;

	unique_Base _activeScene;

	void Draw(void);

	std::vector< DrawQueT> _drawList;

	SceneMag();
	~SceneMag();
	bool SysInit(void);
};

