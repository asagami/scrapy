#include "downloader.h"
#include "saver.h"
#include "htmlparser.h"

//下载任务处理单元类，可以同时创建多个对象，由不同的线程进行处理（多任务）
//每个处理单元之间互不干扰。他们共同的操作接口是URLManager
//
class DownloadUnit
{
public:
	//类对象创建工厂函数
	static DownloadUnit* creatUnit(); //对象创建方法
	static void distoryUnit(DownloadUnit * pobj);        //销毁对象方法

	void init();   //对三个模块进行初始化，环境参数从Config类中读取
	void reset();  //下载器单元进行第二次使用调用，作用为重置操作环境
	bool exec();   //处理流程，封装下载器工作的完整流程
	


};
