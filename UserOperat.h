#pragma once

#include<string>

/*
* 用户操作接口
*
* Create by czx
*/

class UserOperat {

	std::string adminLevel;

	public: 
		UserOperat(); //构造函数
		bool userLogin(std::string name, std::string pwd);						    //用户登录
		bool userRegistered(std::string name, std::string pwd, std::string email);  //用户注册
		bool userLoginStatus(std::string server, std::string name);					//用户登录状态

	public:
		UserOperat(std::string admin) {
			this->adminLevel = admin;
		}
};

