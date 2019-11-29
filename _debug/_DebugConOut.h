#pragma once
#ifdef _DEBUG

#include<Windows.h>
#include<memory>

//����
#define AST() {\
	CHAR ast_mes[256];\
	wsprintf(ast_mes, "%s %d�s��\0",__FILE__,__LINE__);\
	MessageBox(0,ast_mes,"�A�T-�g�\��",MB_OK);\
	}


#define TRACE(fmt,...) printf(fmt,__VA_ARGS__);
//�Q�ƌďo��
class _DebugConOut
{
public:
	static  _DebugConOut &GetInstance(void)
	{
		return *Instance;
	}
private:
//��ذ��
	struct _DebugConOutDeleter
	{
		void operator()(_DebugConOut* _debugConOutDeleter) const
		{
			delete _debugConOutDeleter;
		}
	};

	static std::unique_ptr<_DebugConOut, _DebugConOutDeleter> Instance;

	FILE* _debugFp = nullptr;

	_DebugConOut();
	~_DebugConOut();
};

#else //_DEBUG
#define AST()
#define TRACE(fmt,...)
#endif // _DEBUG

