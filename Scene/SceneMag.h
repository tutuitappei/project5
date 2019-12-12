#pragma once
#include<memory>
#include<tuple> 
#include<vector>
#include<map>
#include <comon/Vector2.h>
#include"BaseScene.h"

#define lpSceneMng SceneMag::GetInstance()

enum class DRAW_QUE	//enum clase�����邱�Ƃœ������̂ł��ʂ̌^�Ƃ��Ĉ�����@���S������
{
	IMAGE,
	X,
	Y,
	RAD,
	ZORDER,			//ڲ԰���̕`�揇(���l�̒Ⴂ�ق�����)
	LAYER,			//�D��x�`�揇(������)
	DRAW_MODE,
	DROW_NUM
};
enum class LAYER
{
	BG,
	/*UI,*/
	CHAR,
	UI,
	EX,
	MAX
};

LAYER begin(LAYER);
LAYER end(LAYER);
LAYER operator *(LAYER key);
LAYER operator ++(LAYER& key);

using DrawQueT = std::tuple<int, double, double, double, int, LAYER,int,int>;		//�Ăяo���pQue

class SceneMag
{
public:
	static SceneMag &GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SceneMag();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	};

	void Run(void);							//���s����

	bool AddDrawQue(DrawQueT dQue);			//�`��p����̎擾
	bool AddActQue(ActQueT aQue);			//����ݗp����̎擾

	const Vector2in ScreenSize;				//��ذݻ���
	const Vector2in ScreenCenter;			//��ذݐ^��
	const Vector2in GameScreenSize;			//�ްѽ�ذݻ���
	const Vector2in GameScreenOffset;		//���̾�Ļ���
	int 	gameCnt;						//�ްѓඳ��
private:
	static SceneMag *sInstance;	

	unique_Base _activeScene;	

	void Draw(void);


	int _layerGID;			//�`�潸ذ�

	
	std::vector<ActQueT> _actList;			//�����̷��
	std::vector< DrawQueT> _drawList;		//�摜�̷��

	SceneMag();
	~SceneMag();
	bool SysInit(void);						//������
};

