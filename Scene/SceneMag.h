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
	ZORDER,			//ﾚｲﾔｰ内の描画順(数値の低いほうが奥)
	LAYER,			//優先度描画順(奥から)
	DRAW_MODE,
	DROW_NUM
};
enum class LAYER
{
	BG,
	/*UI,*/
	CHAR,
	UI,
	EX,
	MAX
};

LAYER begin(LAYER);
LAYER end(LAYER);
LAYER operator *(LAYER key);
LAYER operator ++(LAYER& key);

using DrawQueT = std::tuple<int, double, double, double, int, LAYER,int,int>;		//呼び出し用Que

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

	void Run(void);							//実行処理

	bool AddDrawQue(DrawQueT dQue);			//描画用ｷｭｰの取得
	bool AddActQue(ActQueT aQue);			//ｱｸｼｮﾝ用ｷｭｰの取得

	const Vector2in ScreenSize;				//ｽｸﾘｰﾝｻｲｽﾞ
	const Vector2in ScreenCenter;			//ｽｸﾘｰﾝ真ん中
	const Vector2in GameScreenSize;			//ｹﾞｰﾑｽｸﾘｰﾝｻｲｽﾞ
	const Vector2in GameScreenOffset;		//左ｵﾌｾｯﾄｻｲｽﾞ
	int 	gameCnt;						//ｹﾞｰﾑ内ｶｳﾝﾄ
private:
	static SceneMag *sInstance;	

	unique_Base _activeScene;	

	void Draw(void);


	int _layerGID;			//描画ｽｸﾘｰﾝ

	
	std::vector<ActQueT> _actList;			//動きのｷｭｰ
	std::vector< DrawQueT> _drawList;		//画像のｷｭｰ

	SceneMag();
	~SceneMag();
	bool SysInit(void);						//初期化
};

