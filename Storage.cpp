/*
* C++ ������
*
* const �������Ҫ..
*/

#include<iostream>
#include"Common.h"

const static char* name = "Successful";  //��̬ȫ�ֱ���
const int bufSize = 512;						    //����ʱ��ʼ��
//const int funSize = getSize();					//����ʱ��ʼ��


auto pi = 3.1415926;	  // ��������ʱ���ݳ�ʼ�����ʽ�Զ��ƶϸñ���������
auto queryMsg("re");	  // ��������ʱ��������ֵ��ռλ��
extern int num=0;			  // ��������Ѿ�����ʼ��, ��ֵΪ�����ֵ,  ���û�б���ʼ��, ��ֵΪ 0

thread_local int x;

void write_extern(void) {
	register int miles;  //���ڶ���洢�ڼĴ����ж����� RAM �еľֲ�����
	std::cout << num << std::endl;
}

//const ������
void ref_const() {
	const int i = 10;
	const int& j = i;
}

// const ��ָ��
void pot_const() {
	const double pi = 3.14;
	const double* ref_pi = &pi;
	//double* ref_pi = &pi;  //����
}

// ���� const
void top_const() {
	//double *const pot_pi = &dou_pi;  ���ɱ��ı�ֵ
}