#include <Dxlib.h>
#include<algorithm>
#include<_debug\_DebugDispOut.h>
#include<comon\ImageMng.h>
#include "SceneMag.h"
#include"GameScene.h"
#include"Title.h"
#include<Obj.h>

SceneMag* SceneMag::sInstance = nullptr;

LAYER begin(LAYER)
{
	return LAYER::BG;
}

LAYER end(LAYER)
{
	return LAYER::MAX;
}

LAYER operator*(LAYER key)
{
	return key;
}

LAYER operator++(LAYER & key)
{
	return key = static_cast<LAYER>(std::underlying_type<LAYER>::type(key) + 1);
}

SceneMag::SceneMag() : ScreenSize{ 800,600 },ScreenCenter{ScreenSize/2},GameScreenSize{500,390},GameScreenOffset{(ScreenSize-GameScreenSize)/2}
{
	gameCnt = 0;
}

void SceneMag::Draw(void)
{
	std::sort(_drawList.begin(), _drawList.end(), [](DrawQueT dQueA, DrawQueT dQueB){ 

		return	std::tie(std::get<static_cast<int>(DRAW_QUE::LAYER)>(dQueA),std::get<static_cast<int>(DRAW_QUE::ZORDER)>(dQueA))
				< 
				std::tie(std::get<static_cast<int>(DRAW_QUE::LAYER)>(dQueB), std::get<static_cast<int>(DRAW_QUE::ZORDER)>(dQueB));
	});


	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();

	LAYER drawLayer = LAYER::BG;
	int blendMode = DX_BLENDMODE_NOBLEND;
	int blendNum = 255;

	SetDrawScreen(_layerGID);
	ClsDrawScreen();
	SetDrawBlendMode(blendMode, blendNum);

	//ｽﾀｯｸにたまっているQueを描画する
	//for (int i = 0; i < _drawList.size(); i++)
	//{
	//	DrawGraph(
	//		std::get<static_cast<int>(DRAW_QUE::X)>(_drawList[i]),
	//		std::get<static_cast<int>(DRAW_QUE::Y)>(_drawList[i]),
	//		std::get<static_cast<int>(DRAW_QUE::IMAGE)>(_drawList[i]),
	//		true);
	//}
	//for (auto date:_drawList)
	//{
	//	DrawGraph(
	//		std::get<static_cast<int>(DRAW_QUE::X)>(date),
	//		std::get<static_cast<int>(DRAW_QUE::Y)>(date),
	//		std::get<static_cast<int>(DRAW_QUE::IMAGE)>(date),
	//		true);
	//}
	//for (auto date = _drawList.begin(); date != _drawList.end(); date++)
	//{

	//	DrawRotaGraph(
	//		std::get<static_cast<int>(DRAW_QUE::X)>(*date),
	//		std::get<static_cast<int>(DRAW_QUE::Y)>(*date),
	//		1.0,
	//		std::get<static_cast<int>(DRAW_QUE::RAD)>(*date),
	//		std::get<static_cast<int>(DRAW_QUE::IMAGE)>(*date),
	//		true);
	//}

	//ｽﾀｯｸにたまっているQueを描画する
	for (auto dQue : _drawList)
	{
		double x, y, rad;
		int id;
		LAYER layer;

		int blendModeOld = blendMode;
		int blendNumOld = blendNum;


		std::tie(id, x, y, rad, std::ignore, layer,blendMode, blendNum) = dQue;

		if ((layer != drawLayer)||(blendModeOld != blendMode) || (blendNumOld != blendNum))
		{
			SetDrawScreen(DX_SCREEN_BACK);
			SetDrawBlendMode(blendModeOld, blendNumOld);


			SetDrawScreen(_layerGID);
			SetDrawBlendMode(blendMode, blendNum);
			ClsDrawScreen();

		}

		DrawRotaGraph(
			static_cast<int>(x),
			static_cast<int>(y),
			1.0,
			rad,
			id,
			true
		);
	}

	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawBlendMode(blendMode, blendNum);

	DrawRotaGraph(ScreenCenter.x, ScreenCenter.y, 1.0, 0, _layerGID, true);

	ClsDrawScreen();

	ScreenFlip();

}

SceneMag::~SceneMag()
{
}

void SceneMag::Run(void)
{
	SysInit();
	_activeScene = std::make_unique<GameScene>();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_drawList.clear();
		AddDrawQue({ IMAGE_ID("枠")[0],400,300,0,0,LAYER::UI,DX_BLENDMODE_NOBLEND,255 });
		_activeScene = (*_activeScene).Update(std::move(_activeScene));
		/*_activeScene->Update();*/
		Draw();
	}
}

bool SceneMag::AddDrawQue(DrawQueT dQue)
{

	if (std::get<static_cast<int> (DRAW_QUE::IMAGE)>(dQue) <= 0)
	{
		//画像IDが不正なので追加しない
		return false;
	}
	//Queを追加
	_drawList.emplace_back(dQue);

	return true;
}

bool SceneMag::AddActQue(ActQueT aQue)
{

	_actList.emplace_back(aQue);
	return true;
}

bool SceneMag::SysInit(void)
{
	bool rtnFlag = true;


	//ｼｽﾃﾑ処理
	SetWindowText("課題5 ギャラガ");

	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);	//			//ﾌﾟﾚｲ画面を800*600ﾄﾞｯﾄ、65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);										//画面windowﾓｰﾄﾞ
	if (DxLib_Init() == -1)										//DXﾗｲﾌﾞﾗﾘの初期化処理
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);								//描画先をﾊﾞｯｸﾊﾞｯﾌｧに設定
	//ScreenSize.x ScreenSize.Y _screenID

	_layerGID = MakeScreen(lpSceneMng.ScreenSize.x, lpSceneMng.ScreenSize.y, true);

	/*srand((unsigned int)time(NULL));*/

	ImageMng::GetInstance().GetID("枠","image/frame.png");
	ImageMng::GetInstance().GetID("black", "image/black.png");
	ImageMng::GetInstance().GetID("white", "image/white.png");

	return false;
}
