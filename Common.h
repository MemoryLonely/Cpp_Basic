#pragma once


const int Name_Id = 12; //��������
extern const int common_size; //��ȡ main �ļ��еĳ�Ա����


// Pointer.cpp  �ĺ�������
void printPointerValue();  
void pointerStatus();
void pointerBuffer();
void increment(int* value);

// Storage.cpp  �ĺ�������
void write_extern(void);
void ref_const();
void pot_const();
void top_const();

// Array.cpp   �ĺ�������
bool insertArray(int value);
int getArrayLength(const int arys[]);