/*

*/
#include<iostream>
#include"Algorithm.h"

//交换数组元素
void SWAP(int* a, int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

//打印输出数组
void printArray(int* a, int len) {
	int i;
	if (len < 1) { //数组长度必须大于0
		printf("length greater than 0");
		return;
	}
	
	printf("[");  //打印整个数组
	for (i = 0; i < len - 1; i++) {
		printf("%d ", a[i]);
	}
	printf("%d]\n", a[len - 1]);
}

//冒泡排序
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