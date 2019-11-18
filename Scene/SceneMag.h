#pragma once
#include<memory>
#include<tuple> 
#include<vector>
#include<map>
#include <comon/Vector2.h>
#include"BaseScene.h"

#define lpSceneMng SceneMag::GetInstance()

enum class DRAW_QUE	//enum clase‚ª‚ ‚é‚±‚Æ‚Å“¯‚¶‚à‚Ì‚Å‚à•Ê‚ÌŒ^‚Æ‚µ‚Äˆµ‚¦‚é@ˆÀ‘S«‚ ‚è
{
	IMAGE,
	X,
	Y,
	RAD,
	ZORDER,  //Ú²Ô°“à‚Ì•`‰æ‡(”’l‚Ì’á‚¢‚Ù‚¤‚ª‰œ)
	LAYER	//—Dæ“x•`‰æ‡(‰œ‚©‚ç)
};
enum class LAYER
{
	BG,
	CHAR,
	UI,
	MAX
};

//•Ê‚Éì‚é
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

