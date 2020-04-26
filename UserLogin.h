#pragma once
#include<string>

/*
* 用户登录相关的操作
*
* Create by czx
*/

class UserLogin {
	public:
		int userLogin(std::string name, std::string pwd);						   //用户登录
		int userRegistered(std::string name, std::string pwd, std::string email);  //用户注册
};

