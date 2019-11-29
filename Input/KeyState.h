#pragma once
#include "InputState.h"
#include<vector>
class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();
	
	void Updata(void) override;		//�X�V
private:
	void RefKeyData(void);
	void SetKeyConfig(void);
	void (KeyState::*func)(void);

	char _buf[256];					//�S�����ް�
	std::vector<int> _keyCon;		//����̨��
	std::vector<int> _keyConDef;	//��̫�ķ���

	INPUT_ID _confID;				//����̨��ID
	int modoKeyOld;					//����̨��Ӱ�ޕύX
};

