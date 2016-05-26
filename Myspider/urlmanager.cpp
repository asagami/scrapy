//#include<urlmanager.h>
#include"downloader.h"
#include"cepoll.h"
#include"chttp.h"
#include"config.h"
#include"csocket.h"
#include"curl.h"
#include"download_unit.h"
#include"htmlparser.h"
#include"inet_content.h"
#include"iurlDbOprator.h"
#include"module.h"
#include"saver.h"
#include"spiderApp.h"
#include"threadpool.h"
#include"urlmanager.h"
//#include"memory_db.h"

CUrl UrlManager::getUrl()
{
	return this->mpDbOperator->getUrl();

}

void UrlManager::saveUrl(string strUrl)
{
	this->mpDbOperator->saveUrl(strUrl);
}

//剩余的业务相关函数实现 略。。。
//

//初始化使用的数据库类型
//1、内存  2、本地数据库产品 3、网络
bool UrlManager::init(int dbType)
{
	switch (dbType)
	{
	case 1:
//		this->mpDbOperator = new MeneryDb();
		break;
	case 2:

	case 3:

	default:
		return false;
	}
}

