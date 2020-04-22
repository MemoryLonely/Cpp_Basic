/*
* C++ 储存类
*
*/

#include<iostream>
#include"Common.h"

const static char* name = "Successful";  //静态全局变量

auto pi = 3.1415926;	  // 声明变量时根据初始化表达式自动推断该变量的类型
auto queryMsg("re");	  // 声明函数时函数返回值的占位符
extern int num;			  // 如果变量已经被初始化, 则值为定义的值,  如果没有被初始化, 则值为 0

thread_local int x;

void write_extern(void) {
	register int miles;  //用于定义存储在寄存器中而不是 RAM 中的局部变量

}
