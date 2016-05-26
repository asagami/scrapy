#include<string>
using namespace std;

#pragma once

class INetContent
{
public:
	void init(size_t bufLength);  //初始化时请求空间

	void init();    //不分配缓冲空间
	size_t initBuf(size_t bufLength);  //当调用不分配缓冲的函数时，要调用此函数

	void setType(string strType);
	string getType();

	unsigned char* getBuf(); //返回保存的数据
	size_t getLength();   //返回数据内容大小

	virtual void release() = 0;  //
protected:
	string m_type;  //数据类型描述
	size_t m_dataLength;  //数据长度
	void *mBuf;   //数据缓冲

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

