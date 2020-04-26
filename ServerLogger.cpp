#include<iostream>

#include "ServerLogger.h"

/*
*  服务器日志
*/


//无参构造函数
ServerLogger::ServerLogger() {
}

/*
* 打印普通类型的日志
*
* @param level  日志等级
* @param msg	日志信息
*/
void ServerLogger::log(int level, std::string msg) {

}

/*
* 打印警告类型的日志
*
* @param level  日志等级
* @param msg	日志信息
*/
void ServerLogger::warn(int level, std::string msg) {

}

/*
* 打印异常类型的日志
*
* @param level  日志等级
* @param msg	日志信息
*/
void ServerLogger::error(int level, std::string msg) {

}