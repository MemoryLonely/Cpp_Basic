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

//打印指针结果
void printPointer() {
	int num_1 = 10;					//初始化一个值为 10 的 int 类型的变量
	int* num_1_P = &num_1;    //初始化一个指针, 获取变量的地址值 

	std::cout << num_1_P << std::endl;  // 获取 num_1 的地址值为 --->  000000ECB00FF494
}

//双指针缓冲区
void pointerBuffer() {
	char* buffer = new char[8];  //创建长度为 8 个字节的缓冲区
	memset(buffer, 0, 8);

	char** ptr = &buffer;

	delete[] buffer;
	std::cin.get();
}