#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define CONFIG_FILE  "/etc/spider.cfg"

#pragma once

//第二种方案辅助类  不严密，仅用来说明原理
class GDate
{
public:
	void Gdate();
	void *getData(int type);  //得到数据，在类外部做强制转换
	char* getChar();
	int getInt();
	float getFloat();
private:
	void * data;
	int data_type;    //string，int，bin
};


class Config  //实现单例模式
{
private://
	Config();  //不对资源进行操作，只用来简单初始化
public:
	static Config *Instance()
	{
		if (_self == NULL)
		{
			_self = new Config();
		}
		return _self;
	}
	static Config* _self;
public:
	bool Load();  //载入配置文件内容并解析
	////////////////////////////////////////
	//读取配置项的第一种方案：每个配置项存在一个函数
	///////////////////////////////////////////
	int getMaxJobNum();
	string getSeeds();
	string substring();
	bool getMakeHistoryDir();
	vector<string> &getModuls();


private:  //第一种方案的数据存储结构
	int max_job_num;
	string seeds;
	bool make_historydir;
	vector<string> modules;

private: //第二种方案的数据存储结构
	//map<string, string> params;
	//vector<string> modules;

private://私有操作（内部接口）
	bool parse()  //解析文件到成员变量
	{ 
		vector<string> strList;
		
		int pos, last_pos = 0;
	//过滤注释，分为两种情况：A行首存在注释符号，B行中间存在注释符号，假如注释符号存在于双引号内，不做处理
		


	}

	string config_text;  //保存读取的文件内容

};

Config *Config::_self = NULL;  //单例初始化
