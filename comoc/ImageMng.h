#pragma once
#include<map>
#include<memory>
#include<vector>
#include"Vector2.h"

using VecInt = std::vector<int>;

#define lpImageMng ImageMng::GetInstance()
#define IMAGE_ID(KEY) (ImageMng::GetInstance().GetID)

class ImageMng
{
public:
	static ImageMng &GetInstance(void)
	{
		return *Instance;
	}

	//static void Destroy()
	//{
		//if (Instance != nullptr)
		//{
		//	delete Instance;
		//}
		//Instance = nullptr;
	//}

	const  VecInt& GetID(const std::string& key);
	const  VecInt& GetID(const std::string& key, const std::string& fileName);
	const  VecInt& GetID(const std::string& key, const std::string& fileName, const Vector2& divSize, const Vector2& divCnt);

private:
	struct ImageMngDeleter
	{
		void operator()(ImageMng* imageMng) const
		{
			delete imageMng;
		}
	};

	static std::unique_ptr<ImageMng,ImageMngDeleter> Instance;

	ImageMng();
	~ImageMng();

	std::map<std::string, VecInt> imgMap;

};
