#include<iostream>
#include"Algorithm.h"
#include"Common.h"
#include"OutPrint.h"       //�����ӡ��־����

/*
*
*
*/

const int _NameId = Name_Id; //��ȡ common �ļ��еĳ�Ա����

/*
* �����������
*/
int main() {
	int arr[] = { 9,0,6,5,8,2,1,7,4,3 };
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len);
	UBU(arr, len);
	printArray(arr, len);

	return 0;
}


