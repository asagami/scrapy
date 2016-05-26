#include<string>
#include"inet_content.h"
#include"chttp.h"

using namespace std;

#pragma once

class Downloader
{
public:
	bool get(string strUrl);  //HTTP GET ������Դ��ȡ�ɹ�����true�����ص����������Ա�������ݹ�����ά����
	bool post(string strUrl, unsigned char* buf/*�ύ����*/, size_t length/*�ύ���ݻ������Ĵ�С*/);  //HTTP POST����
	//������Լ������HTTP֧�ֵ���������
	//������
	INetContent *getContent();//������غ������
	Downloader();
	~Downloader();
	void init();//��ʼ��������,�������õ�����Դ
	bool download(string strUrl);/////
	void reset();  //����������״̬��Ŀ�ģ���ֹ����������ͷ��ڴ���Դ����������˷�
	void release(); //�ͷ���Դ ����ʱ���ã���������������
private:
	bool doDownload(string strUrl);  //��װ���ش�������
private:
	IHttp * m_http;   //HTTPЭ��֧����
	//INetContent * m_content;   //�������ȱ�ݣ����Խ��е���

};
