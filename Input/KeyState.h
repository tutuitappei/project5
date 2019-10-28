#pragma once
#include "InputState.h"
#include<vector>
class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();
	
	void Updata(void) override;
private:
	void RefKeyData(void);
	void SetKeyConfig(void);
	void (KeyState::*func)(void);

	char _buf[256];
	std::vector<int> _keyCon;
	std::vector<int> _keyConDef;

	INPUT_ID _confID;
	int modoKeyOld;
};

