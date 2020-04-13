#include<iostream>
#include"Common.h"
#include"OutPrint.h" //负责打印日志内容
/*

*/

const int _NameId = Name_Id; //获取 common 文件中的

int main() {
	int a = 5;
	increment(&a);

	std::cout << _NameId << std::endl;

	return 0;
}
