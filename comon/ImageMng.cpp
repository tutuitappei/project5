#include "ImageMng.h"
#include<map>
#include<Dxlib.h>

std::unique_ptr<ImageMng,ImageMng::ImageMngDeleter> ImageMng::Instance(new ImageMng());
//ImageMng* ImageMng::Instance = nullptr;

const VecInt & ImageMng::GetID(const std::string & key)
{
	if (imgMap.find(key) == imgMap.end())

	return GetID(key,key);
}

const VecInt & ImageMng::GetID(const std::string & key, const std::string fileName)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(1);
		imgMap[key][0] = LoadGraph(fileName.c_str());
	}
	return imgMap[key];
}

const VecInt & ImageMng::GetID(const std::string & key, const std::string fileName, const Vector2in divSize, const Vector2in divCnt)
{
	if (imgMap.find(key) == imgMap.end())
	{
		/*VecInt tmpDate;*/
		imgMap[key].resize(divCnt.x * divCnt.y);
		LoadDivGraph(
			fileName.c_str(),
			divCnt.x*divCnt.y,
			divCnt.x,
			divCnt.y,
			divSize.x,
			divSize.y,
			&imgMap[key][0]);
		/*if (
		LoadDivGraph(
			fileName.c_str(),
			divCnt.x*divCnt.y,
			divCnt.x,
			divCnt.y,
			divSize.x,
			divSize.y,
			&imgMap[key][0]);
		 == 0)
		{
			imgMap[key] = std::move(tmpDate);
		}
		else
		{
			return std::move(tmpDate);
		}*/
	}
	return imgMap[key];
}

ImageMng::ImageMng()
{
}


ImageMng::~ImageMng()
{
}
