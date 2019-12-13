#pragma once
#include "Obj.h"
#include<memory>
#include<InputState.h>
class player :
	public Obj
{
public:
	player();
	player(Vector2db pos, Vector2db size);	//座標、ｻｲｽﾞ
	void Update(sharedOdj plObj) override;
	~player();

private:
	void init(void);					//初期化
	std::shared_ptr<InputState> _input;	//ｷｰ操作情報
};

