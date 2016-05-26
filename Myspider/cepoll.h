//#include"cepoll.h"
#include<iostream>
#include"csocket.h"

using namespace std;
#pragma once

class CEpoll
{
public:
	//封装epoll机制，总共三个操作

	void init();
	void addHandle();
	void releaseHandle();
	void regestSocket(CSocket *objSocket)
	{
		//得到socket对象中保存的socket句柄
		//把句柄注册到socket框架中哦昂
	}

	//单例实现
};