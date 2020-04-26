#pragma once
#include<string>

/*
* 服务端日志打印
*
* Create by czx
*/

class ServerLogger {
public:
	// 日志等级类型  -- 普通, 警告
	enum level { ordinary, serious};  
public:
	ServerLogger();
	void log(int level, std::string msg);
	void warn(int level, std::string msg);
	void error(int level, std::string msg);
};

