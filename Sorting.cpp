/*

*/
#include<iostream>
#include"Algorithm.h"

//��������Ԫ��
void SWAP(int* a, int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

//��ӡ�������
void printArray(int* a, int len) {
	int i;
	if (len < 1) { //���鳤�ȱ������0
		printf("length greater than 0");
		return;
	}
	
	printf("[");  //��ӡ��������
	for (i = 0; i < len - 1; i++) {
		printf("%d ", a[i]);
	}
	printf("%d]\n", a[len - 1]);
}

//ð������
void UBU(int* a, int len) {
	int max = len - 1;
	int i, j;
	for (i = 0; i < max; i++) {
		for (j = 0; j < max - i; j++) {
			if (a[j + 1] < a[j]) {
				SWAP(a, j, j + 1);
			}
		}
	}
}