//#include"cepoll.h"
#include<iostream>
#include"csocket.h"

using namespace std;
#pragma once

class CEpoll
{
public:
	//��װepoll���ƣ��ܹ���������

	void init();
	void addHandle();
	void releaseHandle();
	void regestSocket(CSocket *objSocket)
	{
		//�õ�socket�����б����socket���
		//�Ѿ��ע�ᵽsocket�����Ŷ��
	}

	//����ʵ��
};