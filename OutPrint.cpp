#include "OutPrint.h"
#include<iostream>
/*
	�������������־
*/

using namespace std;

void printString(const char* param) {
	cout << param << endl;
}

void printString(int id, const char* param) {
	cout << "{[_" << id << "_], " << param << "}" << endl;
}

void printString(const char* param, const char* msg) {
	cout << msg << "--->" << param << endl;
}

void printString(int id, const char* param, const char* msg) {
	cout << msg << "---> {[_" << id << "_], " << param << "}" << endl;
}

void printNumber(int param) {
	cout << param << endl;
}

void printNumber(int id, int param) {
	cout << "{[_" << id << "_], " << param << "}" << endl;
}

void printNumber(int param, const char* msg) {
	cout << msg << "--->" << param<< endl;
}

void printNumber(int id, int param, const char* msg) {
	cout << msg << "---> {[_" << id << "_], " << param << "}" << endl;
}