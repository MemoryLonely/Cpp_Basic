#pragma once
/* 
* ����ʾ���� C++ ��
*
* ��ͷ�ļ������������ͱ���  https://www.yiibai.com/cplusplus/cpp-friend-function.html#article-start
*/
class ObjectFunction {
	//���� public ����
	public:
		int id;
		static float cont;
		const char* name;

	private:
		bool lift;
		enum sex {man, wman, child };

	//���� public ����
	public: 
		ObjectFunction();
		ObjectFunction(int i, const char* n);
		int sum(int a, int b);
};

