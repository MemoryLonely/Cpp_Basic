/*
* C++ 指针相关的练习和操作
*
* 指针, 就是保存有对应数据类型的的数据的地址值的变量
* & --> 取地址符, 获取对象的地址;	*  --> 解引用符, 访问指针的对象
*/
#include<iostream>
#include<cstdlib>

using namespace std;

//打印指针结果
void printPointerValue() {
	int num_1 = 10;					//初始化一个值为 10 的 int 类型的变量
	int* num_1_P = &num_1;    //初始化一个指针, 获取变量的地址值 

	std::cout << *num_1_P << std::endl;
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