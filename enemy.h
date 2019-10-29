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
	MAX
};

using EnemyState = std::tuple<ENEMY_TYPE, ENEMY_STATE::VECTOR, ENEMY_STATE::SIZE>;

class enemy :
	public Obj
{
public:
	enemy();
	enemy(EnemyState a);
	void Update(void) override;
	~enemy();

private:
	EnemyMove moveCtl{ _pos };
	void init(void);
	ENEMY_TYPE _type;
};

