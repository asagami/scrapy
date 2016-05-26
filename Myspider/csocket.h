
#include <stdio.h>
using namespace std;

#pragma once

//��װsocket�ͻ��˲���
class CSocket
{
	//������Ԫ�࣬����epoll�����
public:

	friend class CEpoll;
public:
	//socket��Ҫ����
	bool connect();
	size_t read(char * buf, size_t lenth);
	size_t write(char * buf, size_t lenth);
	void close();

	void setIp();
	void setPort();
	bool isConnect();  //��⵱ǰsocket�����Ƿ�������״̬

private:
	int m_socketHandle;   //socket���
	int m_ip;
	int m_port;
};

//���ʹ���ഴ������ģʽ��
class SocketFactory
{
	static CSocket* getSocketObj();
};
