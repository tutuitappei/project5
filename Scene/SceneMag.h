#pragma once
#include<memory>
#include<tuple>  //3�ȏ�̈Ⴄ�^�̗v�f����舵��(2�̎���pair)
#include<vector>
#include <comon/Vector2.h>
#include"BaseScene.h"

#define lpSceneMng SceneMag::GetInstance()

enum class DRAW_QUE	//enum clase�����邱�Ƃœ������̂ł��ʂ̌^�Ƃ��Ĉ�����@���S������
{
	IMAGE,
	X,
	Y,
	RAD,
	ZORDER,  //ڲ԰���̕`�揇(���l�̒Ⴂ�ق�����)
	LAYER	//�`�揇(������)
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

