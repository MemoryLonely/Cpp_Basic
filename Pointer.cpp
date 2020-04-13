/*
* C++ ָ����ص���ϰ�Ͳ���
*
* ָ��, ���Ǳ����ж�Ӧ�������͵ĵ����ݵĵ�ֵַ�ı���
* & --> ȡ��ַ��, ��ȡ����ĵ�ַ;	*  --> �����÷�, ����ָ��Ķ���
*/
#include<iostream>
#include<cstdlib>

using namespace std;

//��ӡָ����
void printPointerValue() {
	int num_1 = 10;					//��ʼ��һ��ֵΪ 10 �� int ���͵ı���
	int* num_1_P = &num_1;    //��ʼ��һ��ָ��, ��ȡ�����ĵ�ֵַ 

	std::cout << *num_1_P << std::endl;
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