#pragma once


const int Name_Id = 12; //声明常量
extern const int common_size; //获取 main 文件中的成员变量


// Pointer.cpp  的函数声明
void printPointerValue();  
void pointerStatus();
void pointerBuffer();
void increment(int* value);

// Storage.cpp  的函数声明
void write_extern(void);
void ref_const();
void pot_const();
void top_const();

// Array.cpp   的函数声明
bool insertArray(int value);
int getArrayLength(const int arys[]);