#pragma once
/* 
* 用作示例的 C++ 类
*
* 在头文件中声明函数和变量  https://www.yiibai.com/cplusplus/cpp-friend-function.html#article-start
*/
class ObjectFunction {
	//声明 public 变量
	public:
		int id;
		static float cont;
		const char* name;

	private:
		bool lift;
		enum sex {man, wman, child };

	//声明 public 函数
	public: 
		ObjectFunction();
		ObjectFunction(int i, const char* n);
		int sum(int a, int b);
};

