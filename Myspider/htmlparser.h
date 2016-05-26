#include<string>
#include<vector>
#include"inet_content.h"

using namespace std;

#pragma once

//所有网络内容解析器的接口抽象类
class IContentPaser
{
public:
	virtual vector< string> getUrls() = 0;   //得到解析后的Url列表
	virtual bool parse() = 0;	//解析函数
	virtual bool checkcontent() = 0;  //检查内容是否合法
	virtual string getVersion() = 0;  //得到文档的版本
	virtual string getBuf() = 0;
	virtual void setContent(INetContent *objContent) = 0;  //把内容传给解析类
};

//内容解析类的基类
class ContentParser : public IContentPaser
{
public:
	virtual void setContent(INetContent *objContent)
	{
		this->m_pContent = (IContentPaser*)objContent;
	}

	virtual vector< string> getUrls() = 0;   //得到解析后的Url列表
	virtual bool parse() = 0;	//解析函数
	virtual bool checkcontent() = 0;  //检查内容是否合法
	virtual string getVersion() = 0;  //得到文档的版本
	virtual string getBuf() = 0;
//protected:
	IContentPaser * m_pContent;
};


class HtmlParserBase : public ContentParser
{
public:
	virtual ~HtmlParserBase();
	virtual vector< string> getUrls()   //得到解析后的Url列表
	{
		//返回成员变量m_pPageUrlList的对象
		return m_pPageUrlList;
	}
	virtual bool parse() = 0;	//解析函数
	virtual bool checkcontent() = 0;  //检查内容是否合法
	virtual string getVersion() = 0;  //得到文档的版本

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
	vector< string> m_pPageUrlList;  //用于保存页面内的Url列表
};

class HtmlParser4 : public HtmlParserBase
{
	virtual ~HtmlParser4();
	virtual bool parse();	//解析函数
	virtual bool checkcontent();  //检查内容是否合法
	virtual string getVersion();  //得到文档的版本
	 string getBuf() ;
};



class HtmlParser5 : public HtmlParserBase
{
	virtual ~HtmlParser5();
	virtual bool parse();	//解析函数
	virtual bool checkcontent();  //检查内容是否合法
	virtual string getVersion();  //得到文档的版本
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


