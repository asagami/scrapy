#include<string>


using namespace std;


class IModule
{
public:
	void init() ;
	void * getFunction();
protected:
	//1、版本编号
	//2、提供的成员函数
	//


};

class ModuleManager  //模块管理器，在初始化时根据配置文件的参数将 .so中的描述结构反射出，并保存
{
public:
	//根据关键字找到相关的模块，初始化并调用

};
