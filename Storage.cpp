/*
* C++ 储存类
*
* const 好像很重要..
*/

#include<iostream>
#include"Common.h"

const static char* name = "Successful";  //静态全局变量
const int bufSize = 512;						    //编译时初始化
//const int funSize = getSize();					//运行时初始化


auto pi = 3.1415926;	  // 声明变量时根据初始化表达式自动推断该变量的类型
auto queryMsg("re");	  // 声明函数时函数返回值的占位符
extern int num=0;			  // 如果变量已经被初始化, 则值为定义的值,  如果没有被初始化, 则值为 0

thread_local int x;

void write_extern(void) {
	register int miles;  //用于定义存储在寄存器中而不是 RAM 中的局部变量
	std::cout << num << std::endl;
}

//const 的引用
void ref_const() {
	const int i = 10;
	const int& j = i;
}

// const 和指针
void pot_const() {
	const double pi = 3.14;
	const double* ref_pi = &pi;
	//double* ref_pi = &pi;  //错误
}

// 顶层 const
void top_const() {
	//double *const pot_pi = &dou_pi;  不可被改变值
}