//#include"csocket.h"
#include<vector>
#include<map>
#include<string>
#include"cepoll.h"
using namespace std;
#pragma once


class HttpHead  //实现时完全进行字符串操作
{
public:
	void setParam(string strProc, string strValue);  //设置HTTP头属性，编码时注意属性的唯一性
	string getParam(string strProc);   //得到某一个HTTP头属性
	//定义固定头参数操作方法
	void setAccept(string strValue); //Accept属性操作方法
	string getAccept(string strValue);  //
	//可以根据HTTP协议文档继续扩充操作方法列表
	//。。。

	//得到HTTP头内容
	string getHeadText();   //把内部数据结构中保存的属性拼接成完整的HTTP头内容文本
	void setHeadText(string strHeadText);  //根据头文本内容生成内部数据结构并保存
private:
	map<string, string> m_heads;
};

/*
* 抽象类
* 其子类的使用流程：
* 1、初始化，init， 初始化请求头（get方法之前）
* 2、调用get方法
* 3、得到返回头
* 4、释放资源，若想反复使用对象，那么调用reset，再返回第一步
*/

typedef struct CHttpData
{
	CHttpData();  //默认构造函数，用接受反馈数据
	CHttpData(size_t bufLength);  //初始化socket使用的缓冲区
	CHttpData(HttpHead &objHead, INetContent * pContent);  //用于发送请请求用,要注意处理过程中能够检查NULL状态
	~CHttpData();  //销毁操作
	 char* getHttpDataBuf();  //得到缓冲区中的数据
	//	size_t getHttpDataLength();       //得到缓冲区中数据的长度
	 int getHttpDataLength();
	size_t get();
	bool parse();  //接收到数据后主动调用此方法进行数据反向还原，把数据包恢复为头和内容
	HttpHead getHead();
	INetContent* getContent();
	void parseDate();   //用于解析从网络返回的数据
private:  //生成发送数据包与解析接受的数据包操作被封装

	void setDate();     //用于拼装要发送的数据
private:
	HttpHead mHead;
	INetContent *m_pContent;   //内容
	unsigned char* m_pBuf; 	   //用于处理Socket传回的数据或要发送的数据

}CHttpData;
/*
class CHttpData :public IHttp //Http数据包结构类
{
public:
	CHttpData();  //默认构造函数，用接受反馈数据
	CHttpData(size_t bufLength);  //初始化socket使用的缓冲区
	CHttpData(HttpHead &objHead, INetContent * pContent);  //用于发送请请求用,要注意处理过程中能够检查NULL状态
	~CHttpData();  //销毁操作
	unsigned char* getHttpDataBuf();  //得到缓冲区中的数据
	//	size_t getHttpDataLength();       //得到缓冲区中数据的长度
	unsigned int getHttpDataLength();
	size_t get();
	bool parse();  //接收到数据后主动调用此方法进行数据反向还原，把数据包恢复为头和内容
	HttpHead getHead();
	INetContent* getContent();
	void parseDate();   //用于解析从网络返回的数据
private:  //生成发送数据包与解析接受的数据包操作被封装

	void setDate();     //用于拼装要发送的数据
private:
	HttpHead mHead;
	INetContent *m_pContent;   //内容
	unsigned char* m_pBuf; 	   //用于处理Socket传回的数据或要发送的数据

};
*/
class IHttp 
{
public:
	virtual void init() ;

	size_t get(string strUrl/*, unsigned char* retbuf, size_t length*/) //封装get方法
	
	{
		//实现思路：
		//1、先对socket封装类进行初始化（设置必要参数，IP、port；调用初始化函数）
		//填充IP的前提条件是先对url中包含的域名做解析


		//2、根据URL和HTTP协议特点生成HTTP头
		HttpHead reqHead;  //按照HTTP1.1规范填充头
		reqHead.setParam("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
		reqHead.setParam("Accept-Language", "zh-CN,zh;q=0.8,zh-TW;q=0.6");
		reqHead.setParam("Connection", "keep-alive");
		//继续填充其他必要的头属性
		//。。。

		this->m_pReqHttpData = new CHttpData(reqHead, NULL);

		//3、通过调用socket向服务器发送请求
		int sendLength = this->mSocket.write(this->m_pReqHttpData->getHttpDataBuf(), this->getHttpDataLength());
		if (sendLength < 0)  //发送状态容错
		{
			//错误处理
			//输出日志：等级警告
		}
		 
		//4、读取服务器返回的数据
		this->m_pResHttpData = new CHttpData(1024 * 128);   //初始化为128K的缓冲区
		int readLength = this->mSocket.read(this->m_pResHttpData->getHttpDataBuf(), 1024 * 128);  //socket阻塞模式
		if (readLength < 0)  //容错
		{
			//容错
		}
		this->m_pResHttpData->parseDate();   //反向还原

		return readLength;
	}
	size_t post(string strUrl, unsigned char* retBuf, size_t length);  //POST方法
	//还可以继续封装其它操作。。。

	void setKeepAlice(bool value);  //是否使用HTTP alive模式
	HttpHead *getHead();
	INetContent* getContent();

	void setHead(HttpHead &head);
	virtual void reset()   //重新初始化对象 ,根据版本差异性，重置或释放的细节可能不同，所以要virtual修饰
	{
		//释放资源并重新申请
		if (m_pReqHttpData != NULL)
		{
			delete m_pReqHttpData;
			m_pReqHttpData = NULL;
		}
		//未完待续......记得释放其他资源
	}
	virtual void release()  //释放申请的资源
	{
		//完全释放内存   

	};

	//HttpHead mHttpHead;  //HTTP头结构  缺陷，需要与INetContent进行合并
	//INetContent *m_pContent;
	CHttpData *m_pReqHttpData;  //用于保存请求数据
	CHttpData *m_pResHttpData;  //用于保存反馈数据
protected:
	CSocket mSocket;     //封装的socket类
	size_t getHttpDataLength();

};



class CHttp1_1 : public IHttp
{
public:
	virtual void init()
	{
		//注册socket句柄
		EPoll.regestSocket(&(this->mSocket));

	}
	virtual void reset();

private:
	CSocket mSocket;
	CEpoll EPoll;
};
