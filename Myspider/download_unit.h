#include "downloader.h"
#include "saver.h"
#include "htmlparser.h"

//����������Ԫ�࣬����ͬʱ������������ɲ�ͬ���߳̽��д���������
//ÿ������Ԫ֮�以�����š����ǹ�ͬ�Ĳ����ӿ���URLManager
//
class DownloadUnit
{
public:
	//����󴴽���������
	static DownloadUnit* creatUnit(); //���󴴽�����
	static void distoryUnit(DownloadUnit * pobj);        //���ٶ��󷽷�

	void init();   //������ģ����г�ʼ��������������Config���ж�ȡ
	void reset();  //��������Ԫ���еڶ���ʹ�õ��ã�����Ϊ���ò�������
	bool exec();   //�������̣���װ��������������������
	


};
