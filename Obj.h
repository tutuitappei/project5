#pragma once
#include<string>
#include<vector>
#include<map>
#include<memory>
#include"comon\Vector2.h"


enum class STATE
{
	NORMAL,		//’Êíó‘Ô
	EX,			//“Áêó‘Ô
	DETH,		//€–Só‘Ô
	MAX
};

enum class UNIT_ID
{
	NON,
	PLAYER,		//©‹@
	ENEMY,		//“G
	PL_BULLET,	//©‹@‚Ì’e
	EM_BULLET	//“G‚Ì’e
};

class Obj;

using AnimVector = std::vector<std::pair <int, unsigned int>>;
using sharedOdj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	virtual void Update(/*sharedOdj plObj*/void) = 0;		//î•ñ‚ÌXV
	void Draw(void);										//•`‰æ
	void Draw(int id);										//•`‰æ
	virtual ~Obj();

	bool state(const STATE state);							//½Ã°À½î•ñ‚Ì¾¯Ä
	const STATE state(void) const;							//½Ã°À½î•ñ‚Ìæ“¾

	bool SetAnim(const STATE state, AnimVector& data);		//±ÆÒ°¼®İ‚Ì¾¯Ä

	bool SetAlive(bool alive);								//¶€‚Ì”»’è
	bool isAlive(void) { return _alive; }					//¶‚«‚Ä‚¢‚é‚©
	bool isDead(void) { return _dead; }						//€‚ñ‚Å‚¢‚é‚©
	bool isAnimEnd(void);									//”š”­ˆ—‚ÌI—¹Áª¯¸
private:
	std::map<STATE, AnimVector> _animMap;					//±ÆÒ°¼®İî•ñ‚Ìmap
	STATE _state;											//ó‘Ô
	unsigned int _animFrame;								//ÌÚ°Ñ”
	unsigned int _animCnt;									//±ÆÒ°¼®İ¶³İÄ
protected:
	bool _alive;											//¶‚«‚Ä‚¢‚é
	bool _dead;												//€‚ñ‚Å‚¢‚é
	bool DestroyPrpc(void);									//”š”j±ÆÒ°¼®İ‚ÌI—¹

	int zOrder;												//•`‰æ‚Ì—Dæ“x

	Vector2db _pos;											//À•W
	Vector2db _size;										//»²½Ş
	double _rad;											//Šp“x
};

