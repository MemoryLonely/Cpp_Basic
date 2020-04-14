#include<iostream>
#include"Common.h"
#include"OutPrint.h" //负责打印日志内容

/*
*
*
*/

const int _NameId = Name_Id; //获取 common 文件中的成员变量

int num;

/*
* 程序启动入口
*/
int main() {
	for (int i = 0; i <= 5; i++) {
		insertArray(i);
	}
	return 0;
}


