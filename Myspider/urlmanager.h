#include<string>
#include<iostream>
#include<vector>
//#include "iurldboperator.h"
#include"iurlDbOprator.h"
#include"curl.h"

using namespace std;

//url�����࣬�����ڴ����ݿ⡢�������ݿ��Ʒ���������ݿ�ͻ���ʵ��
//Ϊ�˱�֤���ݵ�Ψһ�ԣ��Ե�����ʽ����
class UrlManager : public IUrlDbOperator
{
public:
	//ҵ����ز���
	CUrl getUrl();
	void saveUrl(string strUrl);
	void saveUrl(vector<string> &urls);
	bool setStatus(CUrl &url);

	//���ʼ������������ʹ����һ�����ݿ�
	bool init(int dbType);
	//����ʵ��
public:
	UrlManager* Instance();
private:
	UrlManager();
	static UrlManager *_self;

private:
	IUrlDbOperator * mpDbOperator;
};

