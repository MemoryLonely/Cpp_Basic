/*
* C++ 指针相关的练习和操作
*
* 指针, 就是保存有对应数据类型的的数据的地址值的变量
* & --> 取地址符, 获取对象的地址;	*  --> 解引用符, 访问指针的对象
*/
#include<iostream>
#include <xmemory>
#include"Common.h"

using namespace std;

//打印指针结果
void printPointerValue() {
	int num_1 = 10;					//初始化一个值为 10 的 int 类型的变量
	int* num_1_P = &num_1;    //初始化一个指针, 获取变量的地址值 

	cout <<"{key='"<< num_1_P <<"'|value='"<< *num_1_P <<"'}"<< endl;
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

//复合类型的数据声明 
void compositeType() {
	int i = 1024;  // int 类型的对象
	int *p = &i;   // int 类型的指针
	int& r = i;      // int 类型的引用
	int* p1, p2;    // p1 是指向 int 的指针, p2 是 int

	int *num = &i;  //指向一个 int 类型的数
	int** numP = &num;  //指向一个 int 类型的指针
	int inn= 100;
	
	cout << *num << endl;
}

//引用类型
void increment(int* value) {
	*value++;
	(*value)++;
	cout << value << endl;
}
