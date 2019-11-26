#pragma once
#include "Obj.h"
#include<memory>
#include<InputState.h>
class player :
	public Obj
{
public:
	player();
	player(Vector2db pos, Vector2db size);//
	void Update(sharedOdj plObj) override;
	~player();

private:
	void init(void);
	std::shared_ptr<InputState> _input;
};

