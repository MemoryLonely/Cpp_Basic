#include"Algorithm.h"		  // 算法
#include"BoostCommon.h"  // Boost 库
#include"Common.h"			  // 通用
#include"MainOpenGL.h"     // OpenGL 库
#include"OutPrint.h"             // 打印日志

#include"ObjectFunction.h"  // OOP 函数对象

/*
* @Create by 苍之弦 2020-04-08 
*/

float ObjectFunction::cont = 0;

// 通用程序启动入口
int main() {
	ObjectFunction of;
	int a = of.sum(1, 2);
	printNumber(a);
	return 0;
}