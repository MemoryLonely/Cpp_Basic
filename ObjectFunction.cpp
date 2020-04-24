#include "ObjectFunction.h"

/*
* 用作示例的 C++ 类
*
* 在源文件中负责实现声明的函数
*/

// 无参构造函数
ObjectFunction::ObjectFunction() {}

// 有参构造函数
ObjectFunction::ObjectFunction(int i, const char* n) {
	this->id = i;
	this->name = n;
}

// 实现加法
int ObjectFunction::sum(int a, int b) {
	int result = 0;
	if (a > b) {
		result = a - b;
		ObjectFunction::cont++;
	} else {
		result = a + b;
		ObjectFunction::cont++;
	}
	return result;
}

// 实现结构体
struct Rectangle {
	int width, height;

	Rectangle() { }

	Rectangle(int w, int h) {
		width = w;
		height = h;
	}
};

void areaOfRectangle() {
	struct  Rectangle ref;
	ref.height = 10;
	ref.width  = 20;
}

//实现枚举
enum week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday }; 

