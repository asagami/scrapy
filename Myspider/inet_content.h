#include<string>
using namespace std;

#pragma once

class INetContent
{
public:
	void init(size_t bufLength);  //��ʼ��ʱ����ռ�

	void init();    //�����仺��ռ�
	size_t initBuf(size_t bufLength);  //�����ò����仺��ĺ���ʱ��Ҫ���ô˺���

	void setType(string strType);
	string getType();

	unsigned char* getBuf(); //���ر��������
	size_t getLength();   //�����������ݴ�С

	virtual void release() = 0;  //
protected:
	string m_type;  //������������
	size_t m_dataLength;  //���ݳ���
	void *mBuf;   //���ݻ���

};

class CTextContent: public INetContent
{
public:
	virtual void release();
};

class CBinContent :public INetContent
{
public:
	virtual void release();
};

