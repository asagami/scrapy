#include<string>
#include"inet_content.h"
#include"chttp.h"

using namespace std;

#pragma once

class Downloader
{
public:
	bool get(string strUrl);  //HTTP GET 方法资源获取成功返回true，下载的内容由类成员变量内容管理类维护，
	bool post(string strUrl, unsigned char* buf/*提交内容*/, size_t length/*提交内容缓冲区的大小*/);  //HTTP POST方法
	//下面可以继续添加HTTP支持的其他方法
	//。。。
	INetContent *getContent();//获得下载后的内容
	Downloader();
	~Downloader();
	void init();//初始化下载器,申请所用到的资源
	bool download(string strUrl);/////
	void reset();  //重置下载器状态，目的，防止反复申请和释放内存资源，造成性能浪费
	void release(); //释放资源 销毁时调用，由析构函数调用
private:
	bool doDownload(string strUrl);  //封装下载处理流程
private:
	IHttp * m_http;   //HTTP协议支持类
	//INetContent * m_content;   //存在设计缺陷，所以进行调整

};
