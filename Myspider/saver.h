#include<iostream>
#include"curl.h"
#include<fstream>
using namespace std;

#pragma once

class ISaver
{
public:
	virtual bool save(CUrl& objUrl, INetContent *pContent) = 0;

};
class Savebase : public ISaver
{
public:
	virtual bool save(CUrl &objUrl, INetContent * pContent) = 0;
	void setSavePath(string strPath);
	void setBackUpPath(string strPath);
	void setBackup(bool isBackup = false);  //Ĭ�ϲ����б��ݲ���
protected:
	bool m_isbackup;    //�Ƿ񱸷ݵı��
	string m_strPath;        //Ĭ�ϱ���·��
	string m_strBackUpPath;  //����·��
};



class LocalSaver : public Savebase
{
public:
	virtual bool save(CUrl &objUrl, INetContent * pContent)
	{
		
		if (this->m_isbackup)
		{
			//������·��

		}
	}
};

class HadoopSaver : public Savebase  //��չ����
{
public:
	virtual bool save(CUrl &objUrl, INetContent * pContent)
	{
		//����ͬLocalSaver����

	}
};
