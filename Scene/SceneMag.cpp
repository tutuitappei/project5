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


	for (auto screen : LAYER())
	{
		SetDrawScreen(_screenID[screen]);
		ClsDrawScreen();
	}

	//�����ɂ��܂��Ă���Que��`�悷��
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

	//�����ɂ��܂��Ă���Que��`�悷��
	for (auto dQue : _drawList)
	{
		double x, y, rad;
		int id;
		LAYER layer;

		std::tie(id, x, y, rad, std::ignore, layer) = dQue;

		if (_screenID[layer] != GetDrawScreen())
		{
			SetDrawScreen(_screenID[layer]);
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
	ClsDrawScreen();

	for (auto layer : LAYER())
	{
		DrawRotaGraph(ScreenCenter.x,ScreenCenter.y,1.0,0,_screenID[layer],true);
	}

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
		AddDrawQue({ IMAGE_ID("�g")[0],400,300,0,0,LAYER::UI });
		_activeScene = (*_activeScene).Update(std::move(_activeScene));
		/*_activeScene->Update();*/
		Draw();
	}
}

bool SceneMag::AddDrawQue(DrawQueT dQue)
{

	if (std::get<static_cast<int> (DRAW_QUE::IMAGE)>(dQue) <= 0)
	{
		//�摜ID���s���Ȃ̂Œǉ����Ȃ�
		return false;
	}
	//Que��ǉ�
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


	//���я���
	SetWindowText("kadai5");

	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);	//			//��ڲ��ʂ�800*600�ޯāA65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);										//���windowӰ��
	if (DxLib_Init() == -1)										//DXײ���؂̏���������
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);								//�`�����ޯ��ޯ̧�ɐݒ�
	//ScreenSize.x ScreenSize.Y _screenID

	_screenID[LAYER::BG] =(MakeScreen(lpSceneMng.ScreenSize.x, lpSceneMng.ScreenSize.y, true));
	_screenID[LAYER::UI] = (MakeScreen(lpSceneMng.ScreenSize.x, lpSceneMng.ScreenSize.y, true));
	_screenID[LAYER::UI] = (MakeScreen(lpSceneMng.ScreenSize.x, lpSceneMng.ScreenSize.y, true));

	/*srand((unsigned int)time(NULL));*/

	ImageMng::GetInstance().GetID("�g","image/frame.png");

	return false;
}
