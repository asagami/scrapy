//#include<pthread.h>
//#include<Mspthrd.h>
#include<list>
#include<queue>
#include<vector>
using namespace std;

//只能给ThreadPool类使用
class ThreadObject  //线程对象类
{
public:
	//成员函数
	ThreadObject();
int 	run();  //启动线程任务
int 	getStatus();  //得到线程状态:运行态和停止态
int 	Temrate();    //强行终止线程，原则上不要强行终止线程，否则会破坏处理流程
int 	setJob(void(*func)(void *));  //设置线程任务
private: //封装pthread库中线程对象的句柄

};

//线程池类
class ThreadPool
{
public:
	ThreadPool();
	ThreadPool(int minJobNum, int maxJobNum)
	{
		//初始化
		this->setMinJobNum(minJobNum);
		this->setMaxJobNum(maxJobNum);

		//生成最小线程对象
	}
	unsigned int newJob(void(*func)(void*))     //开始一个新任务,返回值是线程对象的编号
	{
		
	}

	void selfExex();   //自维护函数，检查任务列表有排队任务的情况，同检查有没有空闲的线程对象，如果条件满足，那么自动绑定


	int hasjob();      //检查线程池内是否存在活动任务
int 	TemrateAll();      //强行终止所有线程

	bool setMinJobNum(int num)
	{
		if (num < 1)
		{
			return false;
		}
		this->m_minJob = num;

	}
int 	setMaxJobNum(int num) //设定线程池最小与最大线程数量
	{
		//注意要认为规定一个理论最大值
		if (num > MAX_THREAD_NUM)
		{
			this->m_maxJob = MAX_THREAD_NUM;
		}
		this->m_maxJob = num;
	}
int 	getJob();//得到线程池内的活动任务数
int 	getJobQuqueNum();   //得到任务队列中等待的任务数

	const int MAX_THREAD_NUM = 1000;  //认为规定一个最大的线程数，防止参数被无意中被设置破坏性能
//private:
	ThreadObject*  creatThreadObj()   //检测边界值，是否超过最大线程数
	{
		
	}
	bool getThreadObj(void(*func)(void *))   //从线程池中找到一个闲置的线程对象并且和任务绑定
	{
		
	}
//private:
	int m_maxJob;
	int m_minJob;
//	quque<void(*func)(void*)> m_jobQuque;    //等待任务队列

	list<ThreadObject *> m_ThreadObjs;    //线程池中所有的线程对象
	vector<ThreadObject*> m_standByList;  //闲置的线程对象索引

};
