#include<Dxlib.h>
#include<algorithm>
#include<_DebugConOut.h>
#include "GameScene.h"
#include<comoc\ImageMng.h>
#include<player.h>
#include<enemy.h>

GameScene::GameScene()
{
	TRACE("ê∂ê¨\n");

	lpImageMng.GetID("∑¨◊", "image/char.png", { 30,32 }, { 10,10 });
	lpImageMng.GetID("íe", "image/shot.png", { 8,3 }, { 1,2 });
	lpImageMng.GetID("ìGîöî≠", "image/en_blast.png", { 64,64 }, { 5,1 });
	lpImageMng.GetID("PLîöî≠", "image/pl_blast.png", { 64,64 }, { 4,1 });
	
	_objList.emplace_back(
			new player({ 400.0,578.0 }, { 0.0,0.0 })
		);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MoveState tmpMoveState;
			tmpMoveState.emplace_back(MOVE_TYPE::WAIT, Vector2db{ (30.0*j),0.0 });//
			tmpMoveState.emplace_back(MOVE_TYPE::PITIN, Vector2db{ 180.0,40.0 });//
			tmpMoveState.emplace_back(MOVE_TYPE::LR, Vector2db{ 400.0,400.0 });//
			EnemyState dete = {ENEMY_TYPE::A,{50*j,40*i}, {0,0}, tmpMoveState };
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
		if (CheckHitKey(KEY_INPUT_D))
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

