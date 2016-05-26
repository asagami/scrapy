#include<string>

using namespace std;
#pragma once

class CUrl
{
public:
	CUrl();
	CUrl(string strUrl);
	CUrl(string &strUrl);

	//getϵ��
	string getUrlString();
	unsigned int getIp();
	//����ʡ��...
	//������
	bool setUrl(string strUrl);
	void setServerIP(unsigned int ip);
	void setOpStatus(int status);
	void setLastOpTime(size_t t);
	void setLocalPath(string path);
private:
	bool parseUrl();  //����URL ͬʱ�ж�URL�Ƿ�Ϸ�
private:
	///////////
	string url;
	string protocal;
	string domain;
	unsigned int port;  //ע��˿ں����޷�������
	string path;
	string fileName;

	//////////
	unsigned int serverIp;  //������IP��ʹ���޷������ͱ�ʾ
	int opStasus;   //����״̬ 0:δץȡ -1:ץȡʧ�� ��������
	time_t lastOpTime;//��һ�εĲ���ʱ��
	string localPath;  //���ر���·��
};

