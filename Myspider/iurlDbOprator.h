#include<string>
#include<vector>
#include"curl.h"
using namespace std;

#pragma once

class IDbOperator
{
public:
	void init() ;
	void release() ;
};


//≥ÈœÛ¿‡
class IUrlDbOperator : public IDbOperator
{
public:
	CUrl getUrl() ;
	void saveUrl(string strUrl) ;
	void saveUrl(vector<string> &urls) ;
	bool setStatus(CUrl &url) ;
};
