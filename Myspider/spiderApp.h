#include<iostream>
#include"config.h"
#include<map>

using namespace std;

//命令行示例： spider -d -seeds www.baidu.com
class CmdLing //命令行处理类
{
public:
	void parse(int argc, char* argv[]);
	string getParam(string paramName);  //返回值是字符串，在使用时不方便，可以使用宏或枚举替换
private:
	map<string, string> Params;
};

class SpiderApp
{
public:

	bool init(int argc, char* argv[]);  //初始化 
	void exec()    //主循环,
	{
		//在运行前线初始化所有单例


	}

	void doExit();  //回收资源，保存数据，清场，接收到退出或终止信号时调用此处理函数

private:
	//成员变量 
	Config* conf;   //配置文件类
	//其他管理器类



};
