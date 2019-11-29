#pragma once
#include<string>
#include<vector>
#include<map>
#include<memory>
#include"comon\Vector2.h"


enum class STATE
{
	NORMAL,		//�ʏ���
	EX,			//������
	DETH,		//���S���
	MAX
};

enum class UNIT_ID
{
	NON,
	PLAYER,		//���@
	ENEMY,		//�G
	PL_BULLET,	//���@�̒e
	EM_BULLET	//�G�̒e
};

class Obj;

using AnimVector = std::vector<std::pair <int, unsigned int>>;
using sharedOdj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	virtual void Update(/*sharedOdj plObj*/void) = 0;		//���̍X�V
	void Draw(void);										//�`��
	void Draw(int id);										//�`��
	virtual ~Obj();

	bool state(const STATE state);							//�ð�����̾��
	const STATE state(void) const;							//�ð�����̎擾

	bool SetAnim(const STATE state, AnimVector& data);		//��Ұ��݂̾��

	bool SetAlive(bool alive);								//�����̔���
	bool isAlive(void) { return _alive; }					//�����Ă��邩
	bool isDead(void) { return _dead; }						//����ł��邩
	bool isAnimEnd(void);									//���������̏I������
private:
	std::map<STATE, AnimVector> _animMap;					//��Ұ��ݏ���map
	STATE _state;											//���
	unsigned int _animFrame;								//�ڰѐ�
	unsigned int _animCnt;									//��Ұ��ݶ���
protected:
	bool _alive;											//�����Ă���
	bool _dead;												//����ł���
	bool DestroyPrpc(void);									//���j��Ұ��݂̏I��

	int zOrder;												//�`��̗D��x

	Vector2db _pos;											//���W
	Vector2db _size;										//����
	double _rad;											//�p�x
};

