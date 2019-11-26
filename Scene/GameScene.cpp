#include<DxLib.h>
#include<time.h>
#include<algorithm>
#include<_DebugConOut.h>
#include<comon\ImageMng.h>
#include"SceneMag.h"
#include "GameScene.h"
#include<player.h>
#include<enemy.h>
#include<bullet.h>
#include<Scene\func\FuncBallet.h>

GameScene::GameScene()
{
	srand(unsigned int(time));

	TRACE("ê∂ê¨\n");

	lpImageMng.GetID("∑¨◊", "image/char.png", { 30,32 }, { 10,10 });
	lpImageMng.GetID("íe", "image/shot.png", { 8,3 }, { 1,2 });
	lpImageMng.GetID("ìGîöî≠", "image/en_blast.png", { 64,64 }, { 5,1 });
	lpImageMng.GetID("PLîöî≠", "image/pl_blast.png", { 64,64 }, { 4,1 });
	
	_objList.emplace_back(
			new player({ lpSceneMng.GameScreenSize.x / 2.0 - 16.0,lpSceneMng.GameScreenSize.y - 16.0 }, { 0.0,0.0 })
		);
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MoveState tmpMoveState;
			tmpMoveState.emplace_back(MOVE_TYPE::WAIT, Vector2db{ 30.0*(j + i * 10), 0.0 });//
			tmpMoveState.emplace_back(MOVE_TYPE::SIGMOID, Vector2db{500.0 ,500.0});//
			tmpMoveState.emplace_back(MOVE_TYPE::SPIRAL, Vector2Template<double>{ (j % 2)*-200.0 + lpSceneMng.GameScreenSize.x / 2 + lpSceneMng.GameScreenOffset.x - 48, lpSceneMng.GameScreenSize.y*(6.0 / 7.0) - 32 * 2 - 8});
			tmpMoveState.emplace_back(MOVE_TYPE::PITIN1, Vector2db{ static_cast<double>(j * 20 + lpSceneMng.GameScreenOffset.x / 2), static_cast<double>(i * 35 + 16 + 35) });//
			tmpMoveState.emplace_back(MOVE_TYPE::LR, Vector2db{ 400.0,400.0 });//
			tmpMoveState.emplace_back(MOVE_TYPE::EXPAND, Vector2db{});
			tmpMoveState.emplace_back(MOVE_TYPE::ATTACK, Vector2db{});
			tmpMoveState.emplace_back(MOVE_TYPE::PITIN2, Vector2db{});
			/*EnemyState dete = {ENEMY_TYPE::A,{50*j,40*i}, {0,0}, tmpMoveState };*/
			EnemyState dete = { static_cast<ENEMY_TYPE>((j + i * 10) % 3) ,{ static_cast<double>(((j + i * 10) % 2)*(lpSceneMng.GameScreenSize.x + 32) - 16),
				static_cast<double>((((j + i * 10) / 2) % 3)*(lpSceneMng.GameScreenSize.y / 2 - 30) + 15) },
			{ 0,0 },tmpMoveState };
			//{
			//	(ENEMY_TYPE)(/*y%3*/0),
			//{ (j*30.0)+15.0,(i*30.0)+16.0 },
			//{ 0.0,0.0 },
			//tmpMoveState 
			//};
			_objList.emplace_back(new enemy(dete));

			
		}
	}
	

	/*obj[0] = new player({100,100},{0,0});*/
	/*obj[0] = new Obj("image/char.png", { 0,0 }, 10, 10, 30, 32);
	obj[1] = new Obj("image/char.png", { 100,100 }, 10, 10, 30, 32);*/
}

GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{

	/*for (int j = 0; j < obj.size(); j++)*/
	/*{
		obj[j]->Draw();
	}*/
	
	/*auto plObj = std::find_if(_objList.begin(),_objList.end(),[&]() {return  == UNIT_ID::PLAYER ; });*/

	for (auto date : _objList)
	{

		(*date).Update(/**plObj*/);
	}

	for(auto date : _objList)
	{
		if (CheckHitKey(KEY_INPUT_F2))
		{
			(*date).SetAlive(false);
		}
		(*date).Draw();
	}

	auto itr =  std::remove_if(_objList.begin(), _objList.end(), [](sharedOdj&obj) {return (*obj).isDead(); });
	
	_objList.erase(itr, _objList.end());
	//_objList.erase(std::remove_if(_objList.begin(), _objList.end(), [](sharedOdj&obj) {return (*obj).isDead(); }), _objList.end());

	return std::move(own);
}

void GameScene::RunActQue(std::vector<ActQueT> actList)
{
	for(auto actQue: actList)
	{
		switch (actQue.first)
		{
		case ACT_QUE::SHOT:
			/*FuncBallet()(actQue, _objList);*/
			break;
		default:
			AST();
			break;
		}

	}
}

