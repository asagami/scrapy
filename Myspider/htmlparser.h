#include<string>
#include<vector>
#include"inet_content.h"

using namespace std;

#pragma once

//�����������ݽ������Ľӿڳ�����
class IContentPaser
{
public:
	virtual vector< string> getUrls() = 0;   //�õ��������Url�б�
	virtual bool parse() = 0;	//��������
	virtual bool checkcontent() = 0;  //��������Ƿ�Ϸ�
	virtual string getVersion() = 0;  //�õ��ĵ��İ汾
	virtual string getBuf() = 0;
	virtual void setContent(INetContent *objContent) = 0;  //�����ݴ���������
};

//���ݽ�����Ļ���
class ContentParser : public IContentPaser
{
public:
	virtual void setContent(INetContent *objContent)
	{
		this->m_pContent = (IContentPaser*)objContent;
	}

	virtual vector< string> getUrls() = 0;   //�õ��������Url�б�
	virtual bool parse() = 0;	//��������
	virtual bool checkcontent() = 0;  //��������Ƿ�Ϸ�
	virtual string getVersion() = 0;  //�õ��ĵ��İ汾
	virtual string getBuf() = 0;
//protected:
	IContentPaser * m_pContent;
};


class HtmlParserBase : public ContentParser
{
public:
	virtual ~HtmlParserBase();
	virtual vector< string> getUrls()   //�õ��������Url�б�
	{
		//���س�Ա����m_pPageUrlList�Ķ���
		return m_pPageUrlList;
	}
	virtual bool parse() = 0;	//��������
	virtual bool checkcontent() = 0;  //��������Ƿ�Ϸ�
	virtual string getVersion() = 0;  //�õ��ĵ��İ汾

	virtual void setContent(INetContent *objContent)
	{
		ContentParser::setContent(objContent);
		this->m_objHtml = this->m_pContent->getBuf();
	}
protected:
	virtual bool parseUrl()
	{
		
		return true;
	}

	string m_objHtml;
	vector< string> m_pPageUrlList;  //���ڱ���ҳ���ڵ�Url�б�
};

class HtmlParser4 : public HtmlParserBase
{
	virtual ~HtmlParser4();
	virtual bool parse();	//��������
	virtual bool checkcontent();  //��������Ƿ�Ϸ�
	virtual string getVersion();  //�õ��ĵ��İ汾
	 string getBuf() ;
};



class HtmlParser5 : public HtmlParserBase
{
	virtual ~HtmlParser5();
	virtual bool parse();	//��������
	virtual bool checkcontent();  //��������Ƿ�Ϸ�
	virtual string getVersion();  //�õ��ĵ��İ汾
};

IContentPaser * parserFactory(string strClassType)
{
	if (strClassType == "html4")
	{
		return new HtmlParser4();
	}

}

void destoryParser(IContentPaser * pContentparser)
{
	delete pContentparser;

}


