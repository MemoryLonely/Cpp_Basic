#include"Algorithm.h"		  // �㷨
#include"BoostCommon.h"  // Boost ��
#include"Common.h"			  // ͨ��
#include"MainOpenGL.h"     // OpenGL ��
#include"OutPrint.h"             // ��ӡ��־

#include"ObjectFunction.h"  // OOP ��������

/*
* @Create by ��֮�� 2020-04-08 
*/

float ObjectFunction::cont = 0;

// ͨ�ó����������
int main() {
	ObjectFunction of;
	int a = of.sum(1, 2);
	printNumber(a);
	return 0;
}