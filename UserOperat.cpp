#include "UserLogin.h"
#include "UserOperat.h"
#include "ServerLogger.h"

/*
* �û������ӿ�ʵ��
*/

ServerLogger log; // ��������־
UserLogin login;  //�û���¼

int flag = 0;

//�޲ι��캯��
UserOperat::UserOperat() {}

//�û���¼
bool UserOperat::userLogin(std::string name, std::string pwd) {
	login.userLogin(name, pwd);
	flag = 1;
}

//�û�ע��
bool UserOperat::userRegistered(std::string name, std::string pwd, std::string email) {
	login.userRegistered(name, pwd, email);
}

/*
* ��ȡ�û���¼״̬
*
* @param server ��������ַ
* @param name   �û�����
* @return true--->�û����� / false--->�û�����
*/
bool UserOperat::userLoginStatus(std::string server, std::string name) {
	log.log(log.ordinary, "");
}

// ��¼״̬
bool loginStatus(std::string server, std::string name) {
	if (flag = 0) {
		return false;
	}
	else {
		return true;
	}
}