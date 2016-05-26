#include"downloader.h"
#include"cepoll.h"
#include"chttp.h"
#include"config.h"
#include"csocket.h"
#include"curl.h"
#include"download_unit.h"
#include"htmlparser.h"
#include"inet_content.h"
#include"iurlDbOprator.h"
#include"module.h"
#include"saver.h"
#include"spiderApp.h"
#include"threadpool.h"
#include"urlmanager.h"
using namespace std;

Downloader::Downloader()
{

}


Downloader::~Downloader()
{

}

void Downloader::init()
{
	//��ʼ��HTTP�࣬�����������
	this->m_http = new CHttp1_1();

}

void Downloader::reset()
{
	this->m_http->reset();

}

void Downloader::release()
{
	if (this->m_http == NULL)
	{
		return;
	}
	this->m_http->release();
	delete this->m_http;
	this->m_http = NULL;
}


bool Downloader::get(string strUrl)
{
	//��װҵ�������еļ����������

	return download(strUrl);
}

bool Downloader::download(string strUrl)
{
	//���⼼���������

	this->m_http->reset(); 

		//���³�ʼ��HTTP�������2
	if (!(this->m_http->get(strUrl)))   //����ҳ��
	{
		return false;
	}
	return true;
}

INetContent* Downloader::getContent()
{
	this->m_http->getContent();
	return 0;
}
