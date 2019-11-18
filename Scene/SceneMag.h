#pragma once
#include<memory>
#include<tuple> 
#include<vector>
#include<map>
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
	LAYER	//�D��x�`�揇(������)
};
enum class LAYER
{
	BG,
	CHAR,
	UI,
	MAX
};

//�ʂɍ��
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

	const Vector2in ScreenSize;
	const Vector2in ScreenCenter;
	const Vector2in GameScreenSize;
	const Vector2in GameScreenOffset;
private:
	static SceneMag *sInstance;

	unique_Base _activeScene;

	void Draw(void);


	std::map<LAYER,int>_screenID;

	



	std::vector< DrawQueT> _drawList;

	SceneMag();
	~SceneMag();
	bool SysInit(void);
};

