#include<iostream>
#include"Algorithm.h"
#include"Common.h"
#include"OutPrint.h"       //负责打印日志内容

/*
*
*
*/

using namespace std;

const int _NameId = Name_Id; //获取 common 文件中的成员变量
extern const int common_size = 520; // extern const 在一个文件中声明, 可以在多个文件中使用

/*
* 程序启动入口
*/
int main() {
	//----------冒泡排序----------
	//int arr[] = { 9,0,6,5,8,2,1,7,4,3 };
	//int len = sizeof(arr) / sizeof(int);
	//printArray(arr, len);
	//UBU(arr, len);
	//printArray(arr, len);
	//----------冒泡排序----------

	cout << common_size << endl;

	return 0;
}


