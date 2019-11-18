#include <Dxlib.h>
#include<algorithm>
#include<_debug\_DebugDispOut.h>
#include<comon\ImageMng.h>
#include "SceneMag.h"
#include"GameScene.h"
#include"Title.h"
#include<Obj.h>

SceneMag* SceneMag::sInstance = nullptr;


SceneMag::SceneMag() : ScreenSize{ 800,600 }//
{
}

void SceneMag::Draw(void)
{
	std::sort(_drawList.begin(), _drawList.end(), [](DrawQueT dQueA, DrawQueT dQueB){
		return 
			std::tie(std::get<static_cast<int>(DRAW_QUE::LAYER)>(dQueA),std::get<static_cast<int>(DRAW_QUE::ZORDER)>(dQueA))
			 < 
			std::tie(std::get<static_cast<int>(DRAW_QUE::LAYER)>(dQueB), std::get<static_cast<int>(DRAW_QUE::ZORDER)>(dQueB));
	});


	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();


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

		DrawRotaGraph(
			static_cast<int>(x),
			static_cast<int>(y),
			1.0,
			rad,
			id,
			true
		);
	}

	ScreenFlip();
}

SceneMag::~SceneMag()
{
}

void SceneMag::Run(void)
{
	SysInit();
	_activeScene = std::make_unique<Title/*Scene*/>();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_drawList.clear();
		AddDrawQue({ IMAGE_ID("�g")[0],0,0,0,1000,LAYER::UI });
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

	MakeScreen(ScreenSize.x,ScreenSize.y,);

	if ()
	{

	}

	/*srand((unsigned int)time(NULL));*/

	ImageMng::GetInstance().GetID("�g","image/frame.png");

	return false;
}
