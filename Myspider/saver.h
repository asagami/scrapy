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
	void setBackup(bool isBackup = false);  //默认不进行备份操作
protected:
	bool m_isbackup;    //是否备份的标记
	string m_strPath;        //默认保存路径
	string m_strBackUpPath;  //备份路径
};



class LocalSaver : public Savebase
{
public:
	virtual bool save(CUrl &objUrl, INetContent * pContent)
	{
		
		if (this->m_isbackup)
		{
			//处理备份路径

		}
	}
};

class HadoopSaver : public Savebase  //扩展功能
{
public:
	virtual bool save(CUrl &objUrl, INetContent * pContent)
	{
		//流程同LocalSaver相似

	}
};
