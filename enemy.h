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

using EnemyState = std::tuple< ENEMY_TYPE, Vector2db, Vector2db, MoveState&>;	//��а�p���(���߁E���W�E���ށE����)

class enemy :
	public Obj
{
public:
	enemy();
	enemy(EnemyState& a);														//�ðĂ��g���ݽ�׸�
	void Update(sharedOdj plObj) override;
	~enemy();

private:
	EnemyMove _moveCtl{ _pos , _rad };											//�G�̓����ɕK�v�ȏ��
	void init(void);															//������
	ENEMY_TYPE _type;															//���
};

