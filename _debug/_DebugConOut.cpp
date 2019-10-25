#ifdef _DEBUG

#include "_DebugConOut.h"
#include<windows.h>




std::unique_ptr<_DebugConOut, _DebugConOut::_DebugConOutDeleter> _DebugConOut::Instance(new _DebugConOut());

_DebugConOut::_DebugConOut()
{
	AllocConsole();
	freopen_s(&_debugFp, "CONOUT$", "w", stdout);
	freopen_s(&_debugFp, "CONIN$", "r", stdin);
}


_DebugConOut::~_DebugConOut()
{
	FreeConsole();
}

#endif // _DEBUG
