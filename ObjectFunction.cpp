#include<iostream>
#include "ObjectFunction.h"

/*
* ����ʾ���� C++ ��
*
* ��Դ�ļ��и���ʵ�������ĺ���
*/

// �޲ι��캯��
ObjectFunction::ObjectFunction() {}

// �вι��캯��
ObjectFunction::ObjectFunction(int i, const char* n) {
	this->id = i;
	this->name = n;
}

// ʵ�ּӷ�����
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

// ʵ�ֽṹ��
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

//ʵ��ö��  ö��������  0  ��ʼ
enum week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday }; 
void printDay() {
	week day;
	day = Monday;
	std::cout << "Day: " << day<< std::endl;
}

