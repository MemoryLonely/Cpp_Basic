/*
* C++ ������
*
*/

#include<iostream>
#include"Common.h"

const static char* name = "Successful";  //��̬ȫ�ֱ���

auto pi = 3.1415926;	  // ��������ʱ���ݳ�ʼ�����ʽ�Զ��ƶϸñ���������
auto queryMsg("re");	  // ��������ʱ��������ֵ��ռλ��
extern int num;			  // ��������Ѿ�����ʼ��, ��ֵΪ�����ֵ,  ���û�б���ʼ��, ��ֵΪ 0

thread_local int x;

void write_extern(void) {
	register int miles;  //���ڶ���洢�ڼĴ����ж����� RAM �еľֲ�����

}
