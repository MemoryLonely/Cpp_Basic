#pragma once

#include<string>

/*
* �û������ӿ�
*
* Create by czx
*/

class UserOperat {

	std::string adminLevel;

	public: 
		UserOperat(); //���캯��
		bool userLogin(std::string name, std::string pwd);						    //�û���¼
		bool userRegistered(std::string name, std::string pwd, std::string email);  //�û�ע��
		bool userLoginStatus(std::string server, std::string name);					//�û���¼״̬

	public:
		UserOperat(std::string admin) {
			this->adminLevel = admin;
		}
};

