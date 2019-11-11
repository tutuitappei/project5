#pragma once
#include<string>
#include<vector>
#include<map>
#include<memory>
#include"comon\Vector2.h"


enum class STATE
{
	NORMAL,
	EX,
	DETH,
	MAX
};

class Obj;

using AnimVector = std::vector<std::pair <int, unsigned int>>;
using sharedOdj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	virtual void Update(void) = 0;
	void Draw(void);
	void Draw(int id);
	virtual ~Obj();

	bool state(const STATE state);
	const STATE state(void) const;

	bool SetAnim(const STATE state, AnimVector& data);
	bool SetAlive(bool alive);
	bool isAlive(void) { return _alive; }
	bool isDead(void) { return _dead; }
	bool isAnimEnd(void);
private:
	std::map<STATE, AnimVector> _animMap;
	STATE _state;
	unsigned int _animFrame;
	unsigned int _animCnt;
protected:
	bool _alive;
	bool _dead;
	bool DestroyPrpc(void);


	Vector2db _pos;
	Vector2db _size;
	double _rad;
};

