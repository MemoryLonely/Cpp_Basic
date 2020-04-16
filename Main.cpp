#include<iostream>
#include"Algorithm.h"
#include"Common.h"
#include"OutPrint.h"       //负责打印日志内容

/*
*
*
*/

const int _NameId = Name_Id; //获取 common 文件中的成员变量

/*
* 程序启动入口
*/
int main() {
	int arr[] = { 9,0,6,5,8,2,1,7,4,3 };
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len);
	UBU(arr, len);
	printArray(arr, len);

	return 0;
}


