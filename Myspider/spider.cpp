#include<iostream>
#include"downloader.h"
#include"cepoll.h"
#include"chttp.h"
#include"config.h"
#include"csocket.h"
#include"curl.h"
#include"download_unit.h"
#include"htmlparser.h"
#include"inet_content.h"
#include"iurlDbOprator.h"
#include"module.h"
#include"saver.h"
#include"spiderApp.h"
#include"threadpool.h"
#include"urlmanager.h"
using namespace std;

int main(int argc, char* argv[])
{
	cout << "...........................";
	SpiderApp app;
	app.init(argc, argv);
	app.exec();
	app.doExit();

	exit(0);
}
