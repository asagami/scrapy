
#include <stdio.h>
using namespace std;

#pragma once

//封装socket客户端操作
class CSocket
{
	//声明友元类，用于epoll框架类
public:

	friend class CEpoll;
public:
	//socket主要操作
	bool connect();
	size_t read(char * buf, size_t lenth);
	size_t write(char * buf, size_t lenth);
	void close();

	void setIp();
	void setPort();
	bool isConnect();  //检测当前socket对象是否在连接状态

private:
	int m_socketHandle;   //socket句柄
	int m_ip;
	int m_port;
};

//如果使用类创建工厂模式：
class SocketFactory
{
	static CSocket* getSocketObj();
};
