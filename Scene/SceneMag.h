#pragma once
#include<memory>
#include<tuple>  //3�ȏ�̈Ⴄ�^�̗v�f����舵��(2�̎���pair)
#include<vector>
#include <comoc/Vector2.h>
#include"BaseScene.h"

using DrawQueT = std::tuple<int, double, double, double>;//

#define lpSceneMag SceneMag::GetInstance()

enum class DRAW_QUE	//enum clase�����邱�Ƃœ������̂ł��ʂ̌^�Ƃ��Ĉ�����@���S������
{
	IMAGE,
	X,
	Y,
	RAD
};

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

	const int ScreenSize;
private:
	static SceneMag *sInstance;

	unique_Base _activeScene;

	void Draw(void);

	std::vector< DrawQueT> _drawList;

	SceneMag();
	~SceneMag();
	bool SysInit(void);
};

