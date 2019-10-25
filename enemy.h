#pragma once
#include "Obj.h"

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

using EnemyState = std::tuple<TYPE, ENEMY_STATE.first, ENEMY_STATE>;

class enemy :
	public Obj
{
public:
	enemy();
	enemy(EnemyState a);
	void Update(void) override;
	~enemy();

private:
	void init(void);
	ENEMY_TYPE _type;
};

