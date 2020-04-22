#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include"MainOpenGL.h"

/*
* Learn OpenGL https://learnopengl-cn.github.io/
*
* version : OpenGL 3.3
*
* GLFW 文档 https://www.glfw.org/docs/latest/window.html#window_hints
*/

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

/*
* 程序启动入口
*/
int main(int argc, char** argv[]) {
	glfwInit();	//初始化 GLFW

	//配置 GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //设置 GLFW 上下文 主版本号(Major) 为 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //设置 GLFW 上下文 次版本号(Minor) 为 3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //使用 核心模式

	//创建窗口对象
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); //将窗口的上下文设置为当前线程的主上下文

	//初始化 GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//设置渲染的窗口尺寸
	glViewport(0, 0, 800, 600);

	//创建渲染循环
	while (!glfwWindowShouldClose(window)) {  //每次循环的开始前检查一次 GLFW 是否被要求退出
		processInput(window);								//检查有事件触发
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);		        //设置清空屏幕所用的颜色
		glClear(GL_COLOR_BUFFER_BIT);			    //清除颜色缓冲之后，整个颜色缓冲都会被填充为glClearColor里所设置的颜色
		glfwSwapBuffers(window);						    //交换颜色缓冲
		glfwPollEvents();
	}

	glfwTerminate(); //释放之前的分配的所有资源
	return 0;
}

//检测 ESC 按键是否被按下, 如果有, 关闭窗口
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

//
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


