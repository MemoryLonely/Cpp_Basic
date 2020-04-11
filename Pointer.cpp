/*
* C++ 指针相关的练习和操作
*
* 指针, 就是保存有对应数据类型的的数据的地址值的变量
* & --> 取地址符, 获取对象的地址;	*  --> 解引用符, 访问指针的对象
*/

#include <xmemory>
#include "OutPrint.h"
#include"Common.h"

//打印指针结果
void printPointer() {
	int num_1 = 10;					//初始化一个值为 10 的 int 类型的变量
	int* num_1_P = &num_1;    //初始化一个指针, 获取变量的地址值 

	printInteger(*num_1_P);
}

//指针的状态
void pointerStatus() {
	int num_1 = 8;
	void* voidPtr = &num_1;  //*voidPtr = 10; 这里会报错, 因为 voidPtr 是一个没有指定内存空间的大小的指针

	double dubVar = 1.0;
	double* duVar_1 = &dubVar;  //true
	double* duVar_2 = duVar_1;    //true

	//int* intVar = duVar_1;	//false
	//intVar = &duVar_1;      //false

	int* nullPrt = 0;  //空指针
	//nullPrt = NULL;  //空指针

	int ival = 1024;
	int* intPtr = &ival;
	if (nullPrt) {}  //true,  nullPrt == 0
	if (intPtr) {}    //false,  intPtr != 0
}


//双指针缓冲区
void pointerBuffer() {
	char* buffer = new char[8];  //创建长度为 8 个字节的缓冲区
	memset(buffer, 0, 8);
	char** ptr = &buffer;
	delete[] buffer;
}