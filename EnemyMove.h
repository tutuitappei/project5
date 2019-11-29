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
	void SetMovePrg(void);										//�s�����e�ւ̈ڍs

	void (EnemyMove::*_move)(void);								//�s���p�����ް�֐��߲���

	void MoveSigmoid(void);										//���Ӳ��
	void MoveSpiral(void);										//��߲��
	void PitIn(void);											//�i�[
	void Wait(void);											//�ҋ@
	void MoveLR(void);											//���E�ړ�
	void MoveExpand(void);										//�g��E�k��
	void MoveAttack(void);										//�U��

	int cnt;													//���ėp����
	int spCnt;													//��߲�ٗp����
	double sigCnt;												//���Ӳ�ޗp����
	int ptinCnt;												//�߯Ĳݗp����
	double moveCnt;												//LR�p����
	double LRCnt;												//LR�����ڰѐ�

	double pai;													//��

	int enemyMax;												//�G�̑���
	static  int enemyCnt;										//LR���̓G��

	MoveState _aim;												//�ړ��^�C�v�A�S�[���n�_���W
	int _aimCnt;												//aim�̌��ݒn
	
	Vector2db & _pos;											//���ݒn
	Vector2db  _oldPos;											//1�ڰёO���W
	
	Vector2db _startPos;										//�J�n�n�_
	
	Vector2db _endPos;											//�I���n�_

	Vector2db _checkPos;										//����

	Vector2db _oneMoveVec;										// �P�ڰѓ�����̈ړ���
	double _moveGain;											// ���Ӳ�ނ̕�

	double spr;													//��߲�ٔ��a
	double spRad;												//��]�p
	double spSpeed;												//���a�k���̑��x

	double& _rad;												//�p�x
};

