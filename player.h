#pragma once
#include "Obj.h"
#include<memory>
#include<InputState.h>
class player :
	public Obj
{
public:
	player();
	player(Vector2 pos,Vector2 size);
	void Update(void) override;
	~player();

private:
	void init(void);
	std::shared_ptr<InputState> _input;
};
