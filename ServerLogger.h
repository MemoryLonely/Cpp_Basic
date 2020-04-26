#pragma once
#include<string>

/*
* �������־��ӡ
*
* Create by czx
*/

class ServerLogger {
public:
	// ��־�ȼ�����  -- ��ͨ, ����
	enum level { ordinary, serious};  
public:
	ServerLogger();
	void log(int level, std::string msg);
	void warn(int level, std::string msg);
	void error(int level, std::string msg);
};

