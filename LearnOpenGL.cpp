#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include"MainOpenGL.h"

/*
* Learn OpenGL https://learnopengl-cn.github.io/
*
* version : OpenGL 3.3
*
* GLFW �ĵ� https://www.glfw.org/docs/latest/window.html#window_hints
*/

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

/*
* �����������
*/
int main(int argc, char** argv[]) {
	glfwInit();	//��ʼ�� GLFW

	//���� GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //���� GLFW ������ ���汾��(Major) Ϊ 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //���� GLFW ������ �ΰ汾��(Minor) Ϊ 3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //ʹ�� ����ģʽ

	//�������ڶ���
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); //�����ڵ�����������Ϊ��ǰ�̵߳���������

	//��ʼ�� GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//������Ⱦ�Ĵ��ڳߴ�
	glViewport(0, 0, 800, 600);

	//������Ⱦѭ��
	while (!glfwWindowShouldClose(window)) {  //ÿ��ѭ���Ŀ�ʼǰ���һ�� GLFW �Ƿ�Ҫ���˳�
		processInput(window);								//������¼�����
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);		        //���������Ļ���õ���ɫ
		glClear(GL_COLOR_BUFFER_BIT);			    //�����ɫ����֮��������ɫ���嶼�ᱻ���ΪglClearColor�������õ���ɫ
		glfwSwapBuffers(window);						    //������ɫ����
		glfwPollEvents();
	}

	glfwTerminate(); //�ͷ�֮ǰ�ķ����������Դ
	return 0;
}

//��� ESC �����Ƿ񱻰���, �����, �رմ���
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

//
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


