#pragma once
#include<string>

/*
* �û���¼��صĲ���
*
* Create by czx
*/

class UserLogin {
	public:
		int userLogin(std::string name, std::string pwd);						   //�û���¼
		int userRegistered(std::string name, std::string pwd, std::string email);  //�û�ע��
};

