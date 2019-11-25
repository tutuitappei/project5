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

	FILE* fp;
	if (fopen_s(&fp, "data/key.dat", "rb") != NULL)
	{
		_keyCon = _keyConDef;
	}
	else
	{
		_keyCon.resize(static_cast<size_t>(end(INPUT_ID())));
		fread(_keyCon.data(), sizeof(_keyCon[0]), _keyCon.size(), fp);

		fclose(fp);
	}

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
		_confID = INPUT_ID::LEFT;
		TRACE("SetKeyConfig\n")
		TRACE("1/8")
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

	auto checkKey = [&](int id) {
		for (auto i = INPUT_ID::LEFT; i < _confID; ++i)
		{
			if (_keyCon[static_cast<int>(i)] == id)
			{
				return false;
			}
		}
		return true;
	};

	for (int id = 0; id < sizeof(_buf); id++)
	{
		if (!checkKey(id))
		{
			continue;
		}

		if (_buf[id] && !_buf[KEY_INPUT_F1])
		{
			_keyCon[static_cast<int>(_confID)] = id;
			++_confID;

			if (_confID == end(_confID))
			{
				FILE* fp;
				if (fopen_s(&fp, "data/key.dat", "wb") != NULL)
				{
					fwrite(_keyCon.data(), sizeof(_keyCon[0]), _keyCon.size(), fp);

					fclose(fp);
				}
				TRACE("RefKeyData\n")
				func = &KeyState::RefKeyData;
			}
			else
			{
				TRACE("ïœçX\n");
				TRACE("%d/%d", static_cast<int>(_confID) + 1, end(INPUT_ID()));
			}
		}
	}
}
