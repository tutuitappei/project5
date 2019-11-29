#pragma once
#include<comon\Vector2.h>
#include<vector>

enum class MOVE_TYPE
{
	WAIT,
	SIGMOID,
	SPIRAL,
	PITIN1,
	LR,
	EXPAND,
	ATTACK,
	PITIN2
};

using MoveState = std::vector<std::pair<MOVE_TYPE, Vector2db>>;

class EnemyMove
{
public:
	EnemyMove(Vector2Template<double>& pos, double& rad);//
	~EnemyMove();
	void UpData(void);
	bool SetMoveState(MoveState& state,bool newFlag);
private:
	void SetMovePrg(void);										//行動内容への移行

	void (EnemyMove::*_move)(void);								//行動用のﾒﾝﾊﾞｰ関数ﾎﾟｲﾝﾀｰ

	void MoveSigmoid(void);										//ｼｸﾞﾓｲﾄﾞ
	void MoveSpiral(void);										//ｽﾊﾟｲﾗﾙ
	void PitIn(void);											//格納
	void Wait(void);											//待機
	void MoveLR(void);											//左右移動
	void MoveExpand(void);										//拡大・縮小
	void MoveAttack(void);										//攻撃

	int cnt;													//ｳｪｲﾄ用ｶｳﾝﾄ
	int spCnt;													//ｽﾊﾟｲﾗﾙ用ｶｳﾝﾄ
	double sigCnt;												//ｼｸﾞﾓｲﾄﾞ用ｶｳﾝﾄ
	int ptinCnt;												//ﾋﾟｯﾄｲﾝ用ｶｳﾝﾄ
	double moveCnt;												//LR用ｶｳﾝﾄ
	double LRCnt;												//LR動作ﾌﾚｰﾑ数

	double pai;													//π

	int enemyMax;												//敵の総数
	static  int enemyCnt;										//LR中の敵数

	MoveState _aim;												//移動タイプ、ゴール地点座標
	int _aimCnt;												//aimの現在地
	
	Vector2db & _pos;											//現在地
	Vector2db  _oldPos;											//1ﾌﾚｰﾑ前座標
	
	Vector2db _startPos;										//開始地点
	
	Vector2db _endPos;											//終了地点

	Vector2db _checkPos;										//距離

	Vector2db _oneMoveVec;										// １ﾌﾚｰﾑ当たりの移動量
	double _moveGain;											// ｼｸﾞﾓｲﾄﾞの幅

	double spr;													//ｽﾊﾟｲﾗﾙ半径
	double spRad;												//回転角
	double spSpeed;												//半径縮小の速度

	double& _rad;												//角度
};

