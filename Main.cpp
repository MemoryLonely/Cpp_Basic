#include<iostream>

/*

*/
void printPointer();
void pointerBuffer();

int main() {
	printPointer();
	pointerBuffer();

	return 0;
}

//��ӡָ����
void printPointer() {
	int num_1 = 10;					//��ʼ��һ��ֵΪ 10 �� int ���͵ı���
	int* num_1_P = &num_1;    //��ʼ��һ��ָ��, ��ȡ�����ĵ�ֵַ 

	std::cout << num_1_P << std::endl;  // ��ȡ num_1 �ĵ�ֵַΪ --->  000000ECB00FF494
}

//˫ָ�뻺����
void pointerBuffer() {
	char* buffer = new char[8];  //��������Ϊ 8 ���ֽڵĻ�����
	memset(buffer, 0, 8);

	char** ptr = &buffer;

	delete[] buffer;
	std::cin.get();
}