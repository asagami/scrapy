#include<iostream>
#include"config.h"
#include<map>

using namespace std;

//������ʾ���� spider -d -seeds www.baidu.com
class CmdLing //�����д�����
{
public:
	void parse(int argc, char* argv[]);
	string getParam(string paramName);  //����ֵ���ַ�������ʹ��ʱ�����㣬����ʹ�ú��ö���滻
private:
	map<string, string> Params;
};

class SpiderApp
{
public:

	bool init(int argc, char* argv[]);  //��ʼ�� 
	void exec()    //��ѭ��,
	{
		//������ǰ�߳�ʼ�����е���


	}

	void doExit();  //������Դ���������ݣ��峡�����յ��˳�����ֹ�ź�ʱ���ô˴�����

private:
	//��Ա���� 
	Config* conf;   //�����ļ���
	//������������



};
