/*
* C++ สýื้
*
*/
#include"Common.h"
#include<iostream>

int msgQueue[10];
int index = 0;

bool insertArray(int value) {
	if (index < 10) {
		msgQueue[index] = value;
		std::cout << index << " -->" << msgQueue[index] << std::endl;
		index++;
	} else {
		return false;
	}
	return true;
}

int getArrayLength(const int arys[]) {
	return sizeof(arys);
}