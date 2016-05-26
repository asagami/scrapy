//#include"csocket.h"
#include<vector>
#include<map>
#include<string>
#include"cepoll.h"
using namespace std;
#pragma once


class HttpHead  //ʵ��ʱ��ȫ�����ַ�������
{
public:
	void setParam(string strProc, string strValue);  //����HTTPͷ���ԣ�����ʱע�����Ե�Ψһ��
	string getParam(string strProc);   //�õ�ĳһ��HTTPͷ����
	//����̶�ͷ������������
	void setAccept(string strValue); //Accept���Բ�������
	string getAccept(string strValue);  //
	//���Ը���HTTPЭ���ĵ�����������������б�
	//������

	//�õ�HTTPͷ����
	string getHeadText();   //���ڲ����ݽṹ�б��������ƴ�ӳ�������HTTPͷ�����ı�
	void setHeadText(string strHeadText);  //����ͷ�ı����������ڲ����ݽṹ������
private:
	map<string, string> m_heads;
};

/*
* ������
* �������ʹ�����̣�
* 1����ʼ����init�� ��ʼ������ͷ��get����֮ǰ��
* 2������get����
* 3���õ�����ͷ
* 4���ͷ���Դ�����뷴��ʹ�ö�����ô����reset���ٷ��ص�һ��
*/

typedef struct CHttpData
{
	CHttpData();  //Ĭ�Ϲ��캯�����ý��ܷ�������
	CHttpData(size_t bufLength);  //��ʼ��socketʹ�õĻ�����
	CHttpData(HttpHead &objHead, INetContent * pContent);  //���ڷ�����������,Ҫע�⴦��������ܹ����NULL״̬
	~CHttpData();  //���ٲ���
	 char* getHttpDataBuf();  //�õ��������е�����
	//	size_t getHttpDataLength();       //�õ������������ݵĳ���
	 int getHttpDataLength();
	size_t get();
	bool parse();  //���յ����ݺ��������ô˷����������ݷ���ԭ�������ݰ��ָ�Ϊͷ������
	HttpHead getHead();
	INetContent* getContent();
	void parseDate();   //���ڽ��������緵�ص�����
private:  //���ɷ������ݰ���������ܵ����ݰ���������װ

	void setDate();     //����ƴװҪ���͵�����
private:
	HttpHead mHead;
	INetContent *m_pContent;   //����
	unsigned char* m_pBuf; 	   //���ڴ���Socket���ص����ݻ�Ҫ���͵�����

}CHttpData;
/*
class CHttpData :public IHttp //Http���ݰ��ṹ��
{
public:
	CHttpData();  //Ĭ�Ϲ��캯�����ý��ܷ�������
	CHttpData(size_t bufLength);  //��ʼ��socketʹ�õĻ�����
	CHttpData(HttpHead &objHead, INetContent * pContent);  //���ڷ�����������,Ҫע�⴦��������ܹ����NULL״̬
	~CHttpData();  //���ٲ���
	unsigned char* getHttpDataBuf();  //�õ��������е�����
	//	size_t getHttpDataLength();       //�õ������������ݵĳ���
	unsigned int getHttpDataLength();
	size_t get();
	bool parse();  //���յ����ݺ��������ô˷����������ݷ���ԭ�������ݰ��ָ�Ϊͷ������
	HttpHead getHead();
	INetContent* getContent();
	void parseDate();   //���ڽ��������緵�ص�����
private:  //���ɷ������ݰ���������ܵ����ݰ���������װ

	void setDate();     //����ƴװҪ���͵�����
private:
	HttpHead mHead;
	INetContent *m_pContent;   //����
	unsigned char* m_pBuf; 	   //���ڴ���Socket���ص����ݻ�Ҫ���͵�����

};
*/
class IHttp 
{
public:
	virtual void init() ;

	size_t get(string strUrl/*, unsigned char* retbuf, size_t length*/) //��װget����
	
	{
		//ʵ��˼·��
		//1���ȶ�socket��װ����г�ʼ�������ñ�Ҫ������IP��port�����ó�ʼ��������
		//���IP��ǰ���������ȶ�url�а���������������


		//2������URL��HTTPЭ���ص�����HTTPͷ
		HttpHead reqHead;  //����HTTP1.1�淶���ͷ
		reqHead.setParam("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
		reqHead.setParam("Accept-Language", "zh-CN,zh;q=0.8,zh-TW;q=0.6");
		reqHead.setParam("Connection", "keep-alive");
		//�������������Ҫ��ͷ����
		//������

		this->m_pReqHttpData = new CHttpData(reqHead, NULL);

		//3��ͨ������socket���������������
		int sendLength = this->mSocket.write(this->m_pReqHttpData->getHttpDataBuf(), this->getHttpDataLength());
		if (sendLength < 0)  //����״̬�ݴ�
		{
			//������
			//�����־���ȼ�����
		}
		 
		//4����ȡ���������ص�����
		this->m_pResHttpData = new CHttpData(1024 * 128);   //��ʼ��Ϊ128K�Ļ�����
		int readLength = this->mSocket.read(this->m_pResHttpData->getHttpDataBuf(), 1024 * 128);  //socket����ģʽ
		if (readLength < 0)  //�ݴ�
		{
			//�ݴ�
		}
		this->m_pResHttpData->parseDate();   //����ԭ

		return readLength;
	}
	size_t post(string strUrl, unsigned char* retBuf, size_t length);  //POST����
	//�����Լ�����װ��������������

	void setKeepAlice(bool value);  //�Ƿ�ʹ��HTTP aliveģʽ
	HttpHead *getHead();
	INetContent* getContent();

	void setHead(HttpHead &head);
	virtual void reset()   //���³�ʼ������ ,���ݰ汾�����ԣ����û��ͷŵ�ϸ�ڿ��ܲ�ͬ������Ҫvirtual����
	{
		//�ͷ���Դ����������
		if (m_pReqHttpData != NULL)
		{
			delete m_pReqHttpData;
			m_pReqHttpData = NULL;
		}
		//δ�����......�ǵ��ͷ�������Դ
	}
	virtual void release()  //�ͷ��������Դ
	{
		//��ȫ�ͷ��ڴ�   

	};

	//HttpHead mHttpHead;  //HTTPͷ�ṹ  ȱ�ݣ���Ҫ��INetContent���кϲ�
	//INetContent *m_pContent;
	CHttpData *m_pReqHttpData;  //���ڱ�����������
	CHttpData *m_pResHttpData;  //���ڱ��淴������
protected:
	CSocket mSocket;     //��װ��socket��
	size_t getHttpDataLength();

};



class CHttp1_1 : public IHttp
{
public:
	virtual void init()
	{
		//ע��socket���
		EPoll.regestSocket(&(this->mSocket));

	}
	virtual void reset();

private:
	CSocket mSocket;
	CEpoll EPoll;
};
