#pragma once
#include<comon\Vector2.h>
#include<vector>

enum class MOVE_TYPE
{
	WAIT,
	SIGMOID,
	SPIRAL,
	PITIN,
	LR
};

using MoveState = std::vector<std::pair<MOVE_TYPE, Vector2db>>;

class EnemyMove
{
public:
	EnemyMove(Vector2db& pos);//
	~EnemyMove();
	void UpData(void);
	bool SetMoveState(MoveState& state,bool newFlag);
private:
	void SetMovePrg(void);

	void (EnemyMove::*_move)(void);

	void MoveSigmoid(void);
	void MoveSpiral(void);
	void PitIn(void);
	void Wait(void);
	void MoveLR(void);

	int cnt;
	int spCnt;
	static int LRCnt;


	MoveState _aim;
	int _aimCnt;
	
	Vector2db & _pos;//
	
	Vector2db _startPos;
	
	Vector2db _endPos;

	double spr;
	double spRad;

	double _rad;

	double rag;
};

