#include "UserLogin.h"
#include "UserOperat.h"
#include "ServerLogger.h"

/*
* 用户操作接口实现
*/

ServerLogger log; // 服务器日志
UserLogin login;  //用户登录

int flag = 0;

//无参构造函数
UserOperat::UserOperat() {}

//用户登录
bool UserOperat::userLogin(std::string name, std::string pwd) {
	login.userLogin(name, pwd);
	flag = 1;
}

//用户注册
bool UserOperat::userRegistered(std::string name, std::string pwd, std::string email) {
	login.userRegistered(name, pwd, email);
}

/*
* 获取用户登录状态
*
* @param server 服务器地址
* @param name   用户名称
* @return true--->用户在线 / false--->用户离线
*/
bool UserOperat::userLoginStatus(std::string server, std::string name) {
	log.log(log.ordinary, "");
}

// 登录状态
bool loginStatus(std::string server, std::string name) {
	if (flag = 0) {
		return false;
	}
	else {
		return true;
	}
}