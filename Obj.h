#pragma once
#include<string>
#include<vector>
#include<map>
#include<memory>
#include"comon\Vector2.h"


enum class STATE
{
	NORMAL,		//通常状態
	EX,			//特殊状態
	DETH,		//死亡状態
	MAX
};

enum class UNIT_ID
{
	NON,
	PLAYER,		//自機
	ENEMY,		//敵
	PL_BULLET,	//自機の弾
	EM_BULLET	//敵の弾
};

class Obj;

using AnimVector = std::vector<std::pair <int, unsigned int>>;
using sharedOdj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	virtual void Update(sharedOdj plObj/*void*/) = 0;		//情報の更新
	void Draw(void);										//描画
	void Draw(int id);										//描画
	virtual ~Obj();

	bool state(const STATE state);							//ｽﾃｰﾀｽ情報のｾｯﾄ
	const STATE state(void) const;							//ｽﾃｰﾀｽ情報の取得

	bool SetAnim(const STATE state, AnimVector& data);		//ｱﾆﾒｰｼｮﾝのｾｯﾄ

	bool SetAlive(bool alive);								//生死の判定
	bool isAlive(void) { return _alive; }					//生きているか
	bool isDead(void) { return _dead; }						//死んでいるか
	bool isAnimEnd(void);									//爆発処理の終了ﾁｪｯｸ
private:
	std::map<STATE, AnimVector> _animMap;					//ｱﾆﾒｰｼｮﾝ情報のmap
	STATE _state;											//状態
	unsigned int _animFrame;								//ﾌﾚｰﾑ数
	unsigned int _animCnt;									//ｱﾆﾒｰｼｮﾝｶｳﾝﾄ
protected:
	bool _alive;											//生きている
	bool _dead;												//死んでいる
	bool DestroyPrpc(void);									//爆破ｱﾆﾒｰｼｮﾝの終了

	int zOrder;												//描画の優先度

	UNIT_ID _unitID;

	Vector2db _pos;											//座標
	Vector2db _size;										//ｻｲｽﾞ
	double _rad;											//角度
};

