#include<_DebugConOut.h>
#include "InputState.h"

InputState::InputState()
{
	for (auto id: INPUT_ID())
	{
		_state.try_emplace(INPUT_ID::LEFT, KeyPair{ 0,1 });
	}
}


InputState::~InputState()
{
}


const KeyMap & InputState::state(void) const
{
	return _state;
}

const KeyPair & InputState::state(INPUT_ID id) const
{
	static KeyPair defDaTa = { 0,0 };

	try
	{
		return _state.at(id);
	}
	catch(...)
	{
		AST();
		return defDaTa;
	}
}

bool InputState::state(INPUT_ID id, int date)
{
	if (_state.find(id) != _state.end())
	{
		_state[id].first = date;
		return true;
	}
	return false;
}

void InputState::SetOld(void)
{
	for (auto id : INPUT_ID())
	{
		try
		{
			_state[id].second = _state[id].first;
		}
		catch (...)
		{
			AST();
			_state.emplace(id, KeyPair{0,1});
		}
	}
}
