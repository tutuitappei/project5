#pragma once
#include<comoc\Vector2.h>
#include<vector>

enum class MOVE_TYPE
{
	WAIT,
	SIGMOID,
	SPIRAL,
	PITIN,
	LR
};

using MoveState = std::vector<std::pair<MOVE_TYPE, Vector2Template<double>>>;//

class EnemyMove
{
public:
	EnemyMove(Vector2Template<double>& pos);//
	~EnemyMove();
	void UpData(void);
	bool SetMoveState(MoveState& state,bool newFlag);
private:

	void (EnemyMove::*_move)(void);

	void MoveSigmoid(void);
	void MoveSpiral(void);
	void PitIn(void);
	void Wait(void);
	void MoveLR(void);

	MoveState _aim;//
	template<class T>
	Vector2Template<double> & _pos;//
};

