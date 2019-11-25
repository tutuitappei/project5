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

	TRACE("¶¬\n");

	lpImageMng.GetID("·¬×", "image/char.png", { 30,32 }, { 10,10 });
	lpImageMng.GetID("e", "image/shot.png", { 8,3 }, { 1,2 });
	lpImageMng.GetID("G­", "image/en_blast.png", { 64,64 }, { 5,1 });
	lpImageMng.GetID("PL­", "image/pl_blast.png", { 64,64 }, { 4,1 });
	
	_objList.emplace_back(
			new player({ lpSceneMng.GameScreenSize.x / 2.0 - 16.0,lpSceneMng.GameScreenSize.y - 16.0 }, { 0.0,0.0 })
		);
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MoveState tmpMoveState;
			tmpMoveState.emplace_back(MOVE_TYPE::WAIT, Vector2db{ (30.0*j),0.0 });//
			tmpMoveState.emplace_back(MOVE_TYPE::SIGMOID, Vector2db{500.0 ,500.0});//
			tmpMoveState.emplace_back(MOVE_TYPE::SPIRAL, Vector2db{ 400.0 ,500.0 });//
			tmpMoveState.emplace_back(MOVE_TYPE::PITIN, Vector2db{ 180.0,40.0 });//
			tmpMoveState.emplace_back(MOVE_TYPE::LR, Vector2db{ 400.0,400.0 });//
			/*EnemyState dete = {ENEMY_TYPE::A,{50*j,40*i}, {0,0}, tmpMoveState };*/
			EnemyState dete = {
				(ENEMY_TYPE)(/*y%3*/0),
			{ (j*30.0)+15.0,(i*30.0)+16.0 },
			{ 0.0,0.0 },
			tmpMoveState };
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

	for (auto date : _objList)
	{

		(*date).Update();
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

