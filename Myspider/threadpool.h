//#include<pthread.h>
//#include<Mspthrd.h>
#include<list>
#include<queue>
#include<vector>
using namespace std;

//ֻ�ܸ�ThreadPool��ʹ��
class ThreadObject  //�̶߳�����
{
public:
	//��Ա����
	ThreadObject();
int 	run();  //�����߳�����
int 	getStatus();  //�õ��߳�״̬:����̬��ֹ̬ͣ
int 	Temrate();    //ǿ����ֹ�̣߳�ԭ���ϲ�Ҫǿ����ֹ�̣߳�������ƻ���������
int 	setJob(void(*func)(void *));  //�����߳�����
private: //��װpthread�����̶߳���ľ��

};

//�̳߳���
class ThreadPool
{
public:
	ThreadPool();
	ThreadPool(int minJobNum, int maxJobNum)
	{
		//��ʼ��
		this->setMinJobNum(minJobNum);
		this->setMaxJobNum(maxJobNum);

		//������С�̶߳���
	}
	unsigned int newJob(void(*func)(void*))     //��ʼһ��������,����ֵ���̶߳���ı��
	{
		
	}

	void selfExex();   //��ά����������������б����Ŷ�����������ͬ�����û�п��е��̶߳�������������㣬��ô�Զ���


	int hasjob();      //����̳߳����Ƿ���ڻ����
int 	TemrateAll();      //ǿ����ֹ�����߳�

	bool setMinJobNum(int num)
	{
		if (num < 1)
		{
			return false;
		}
		this->m_minJob = num;

	}
int 	setMaxJobNum(int num) //�趨�̳߳���С������߳�����
	{
		//ע��Ҫ��Ϊ�涨һ���������ֵ
		if (num > MAX_THREAD_NUM)
		{
			this->m_maxJob = MAX_THREAD_NUM;
		}
		this->m_maxJob = num;
	}
int 	getJob();//�õ��̳߳��ڵĻ������
int 	getJobQuqueNum();   //�õ���������еȴ���������

	const int MAX_THREAD_NUM = 1000;  //��Ϊ�涨һ�������߳�������ֹ�����������б������ƻ�����
//private:
	ThreadObject*  creatThreadObj()   //���߽�ֵ���Ƿ񳬹�����߳���
	{
		
	}
	bool getThreadObj(void(*func)(void *))   //���̳߳����ҵ�һ�����õ��̶߳����Һ������
	{
		
	}
//private:
	int m_maxJob;
	int m_minJob;
//	quque<void(*func)(void*)> m_jobQuque;    //�ȴ��������

	list<ThreadObject *> m_ThreadObjs;    //�̳߳������е��̶߳���
	vector<ThreadObject*> m_standByList;  //���õ��̶߳�������

};
