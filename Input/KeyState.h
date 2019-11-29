#pragma once
#include "InputState.h"
#include<vector>
class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();
	
	void Updata(void) override;		//更新
private:
	void RefKeyData(void);
	void SetKeyConfig(void);
	void (KeyState::*func)(void);

	char _buf[256];					//全ｷｰのﾃﾞｰﾀ
	std::vector<int> _keyCon;		//ｷｰｺﾝﾌｨｸﾞ
	std::vector<int> _keyConDef;	//ﾃﾞﾌｫﾙﾄｷｰｺﾝ

	INPUT_ID _confID;				//ｷｰｺﾝﾌｨｸﾞID
	int modoKeyOld;					//ｷｰｺﾝﾌｨｸﾞﾓｰﾄﾞ変更
};

