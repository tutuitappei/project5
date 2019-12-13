#pragma once
#include "Obj.h"
#include"EnemyMove.h"

enum class ENEMY_TYPE
{
	A,
	B,
	C,
	MAX
};
enum class ENEMY_STATE
{
	TYPE,
	VECTOR,
	SIZE,
	AIM,
	MAX
};

using EnemyState = std::tuple< ENEMY_TYPE, Vector2db, Vector2db, MoveState&>;	//ｴﾈﾐｰ用情報(ﾀｲﾌﾟ・座標・ｻｲｽﾞ・動き)

class enemy :
	public Obj
{
public:
	enemy();
	enemy(EnemyState& a);														//ｽﾃｰﾄを使うｺﾝｽﾄﾗｸﾀ
	void Update(sharedOdj plObj) override;
	~enemy();

private:
	EnemyMove _moveCtl{ _pos , _rad };											//敵の動きに必要な情報
	void init(void);															//初期化
	ENEMY_TYPE _type;															//種類
};

