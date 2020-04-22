#include<iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW\glfw3.h>

/*
	OpenGL Demo
*/

using namespace std;

/*
 OpenGL ≤‚ ‘¿˝
*/
int openWin() {
	glfwInit();//≥ı ºªØ
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//≈‰÷√GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//≈‰÷√GLFW
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);

	if (window == nullptr) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}