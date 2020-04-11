/*
* C++ ָ����ص���ϰ�Ͳ���
*
* ָ��, ���Ǳ����ж�Ӧ�������͵ĵ����ݵĵ�ֵַ�ı���
* & --> ȡ��ַ��, ��ȡ����ĵ�ַ;	*  --> �����÷�, ����ָ��Ķ���
*/

#include <xmemory>
#include "OutPrint.h"
#include"Common.h"

//��ӡָ����
void printPointer() {
	int num_1 = 10;					//��ʼ��һ��ֵΪ 10 �� int ���͵ı���
	int* num_1_P = &num_1;    //��ʼ��һ��ָ��, ��ȡ�����ĵ�ֵַ 

	printInteger(*num_1_P);
}

//ָ���״̬
void pointerStatus() {
	int num_1 = 8;
	void* voidPtr = &num_1;  //*voidPtr = 10; ����ᱨ��, ��Ϊ voidPtr ��һ��û��ָ���ڴ�ռ�Ĵ�С��ָ��

	double dubVar = 1.0;
	double* duVar_1 = &dubVar;  //true
	double* duVar_2 = duVar_1;    //true

	//int* intVar = duVar_1;	//false
	//intVar = &duVar_1;      //false

	int* nullPrt = 0;  //��ָ��
	//nullPrt = NULL;  //��ָ��

	int ival = 1024;
	int* intPtr = &ival;
	if (nullPrt) {}  //true,  nullPrt == 0
	if (intPtr) {}    //false,  intPtr != 0
}


//˫ָ�뻺����
void pointerBuffer() {
	char* buffer = new char[8];  //��������Ϊ 8 ���ֽڵĻ�����
	memset(buffer, 0, 8);
	char** ptr = &buffer;
	delete[] buffer;
}