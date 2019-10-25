#include<Dxlib.h>
#include<_DebugConOut.h>
#include "KeyState.h"
#include"INPUT_ID.h"

KeyState::KeyState()
{
	_keyConDef.reserve(static_cast<size_t>(end(INPUT_ID())));
	_keyConDef.emplace_back(KEY_INPUT_LEFT);
	_keyConDef.emplace_back(KEY_INPUT_RIGHT);
	_keyConDef.emplace_back(KEY_INPUT_UP);
	_keyConDef.emplace_back(KEY_INPUT_DOWN);
	_keyConDef.emplace_back(KEY_INPUT_Z);
	_keyConDef.emplace_back(KEY_INPUT_X);
	_keyConDef.emplace_back(KEY_INPUT_A);
	_keyConDef.emplace_back(KEY_INPUT_S);

	_keyCon = _keyConDef;
	modoKeyOld = 1;

	func = &KeyState::RefKeyData;
}


KeyState::~KeyState()
{
}

void KeyState::Updata(void)
{
	SetOld();
	modoKeyOld = _buf[KEY_INPUT_F1];
	GetHitKeyStateAll(_buf);
	(this->*func)();
}

void KeyState::RefKeyData(void)
{
	for (auto id : INPUT_ID())
	{
		 state(id,_buf[_keyCon[static_cast<int>(id)]]);
	}
	if (_buf[KEY_INPUT_F1] && !modoKeyOld)
	{
		TRACE("SetKeyConfig\n")
		func = &KeyState::SetKeyConfig;
	}
}

void KeyState::SetKeyConfig(void)
{
	if (_buf[KEY_INPUT_F1] && !modoKeyOld)
	{
		TRACE("RefKeyData\n")
		func = &KeyState::RefKeyData;
	}

}
