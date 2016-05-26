#include<string>
#include<iostream>
#include<vector>
//#include "iurldboperator.h"
#include"iurlDbOprator.h"
#include"curl.h"

using namespace std;

//url管理类，兼容内存数据库、本地数据库产品，网络数据库客户端实现
//为了保证数据的唯一性，以单例形式存在
class UrlManager : public IUrlDbOperator
{
public:
	//业务相关操作
	CUrl getUrl();
	void saveUrl(string strUrl);
	void saveUrl(vector<string> &urls);
	bool setStatus(CUrl &url);

	//类初始化函数，决定使用哪一种数据库
	bool init(int dbType);
	//单例实现
public:
	UrlManager* Instance();
private:
	UrlManager();
	static UrlManager *_self;

private:
	IUrlDbOperator * mpDbOperator;
};

