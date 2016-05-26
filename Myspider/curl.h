#include<string>

using namespace std;
#pragma once

class CUrl
{
public:
	CUrl();
	CUrl(string strUrl);
	CUrl(string &strUrl);

	//get系列
	string getUrlString();
	unsigned int getIp();
	//其他省略...
	//。。。
	bool setUrl(string strUrl);
	void setServerIP(unsigned int ip);
	void setOpStatus(int status);
	void setLastOpTime(size_t t);
	void setLocalPath(string path);
private:
	bool parseUrl();  //解析URL 同时判断URL是否合法
private:
	///////////
	string url;
	string protocal;
	string domain;
	unsigned int port;  //注意端口号是无符号整型
	string path;
	string fileName;

	//////////
	unsigned int serverIp;  //服务器IP，使用无符号整型表示
	int opStasus;   //操作状态 0:未抓取 -1:抓取失败 。。。。
	time_t lastOpTime;//上一次的操作时间
	string localPath;  //本地保存路径
};

