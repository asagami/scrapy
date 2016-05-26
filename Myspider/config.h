#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define CONFIG_FILE  "/etc/spider.cfg"

#pragma once

//�ڶ��ַ���������  �����ܣ�������˵��ԭ��
class GDate
{
public:
	void Gdate();
	void *getData(int type);  //�õ����ݣ������ⲿ��ǿ��ת��
	char* getChar();
	int getInt();
	float getFloat();
private:
	void * data;
	int data_type;    //string��int��bin
};


class Config  //ʵ�ֵ���ģʽ
{
private://
	Config();  //������Դ���в�����ֻ�����򵥳�ʼ��
public:
	static Config *Instance()
	{
		if (_self == NULL)
		{
			_self = new Config();
		}
		return _self;
	}
	static Config* _self;
public:
	bool Load();  //���������ļ����ݲ�����
	////////////////////////////////////////
	//��ȡ������ĵ�һ�ַ�����ÿ�����������һ������
	///////////////////////////////////////////
	int getMaxJobNum();
	string getSeeds();
	string substring();
	bool getMakeHistoryDir();
	vector<string> &getModuls();


private:  //��һ�ַ��������ݴ洢�ṹ
	int max_job_num;
	string seeds;
	bool make_historydir;
	vector<string> modules;

private: //�ڶ��ַ��������ݴ洢�ṹ
	//map<string, string> params;
	//vector<string> modules;

private://˽�в������ڲ��ӿڣ�
	bool parse()  //�����ļ�����Ա����
	{ 
		vector<string> strList;
		
		int pos, last_pos = 0;
	//����ע�ͣ���Ϊ���������A���״���ע�ͷ��ţ�B���м����ע�ͷ��ţ�����ע�ͷ��Ŵ�����˫�����ڣ���������
		


	}

	string config_text;  //�����ȡ���ļ�����

};

Config *Config::_self = NULL;  //������ʼ��
