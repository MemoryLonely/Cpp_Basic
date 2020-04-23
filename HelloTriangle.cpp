#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

/*
* OpenGL Graphics Pipeline
*
* 顶点数组对象：Vertex Array Object  ---> VAO
* 顶点缓冲对象：Vertex Buffer Object ---> VBO
* 索引缓冲对象：Element Buffer Object --->EBO (Index Buffer Object ---> IBO)
*

https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/2.2.hello_triangle_indexed/hello_triangle_indexed.cpp
*/

using namespace std;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

// 顶点数据(VBO) X Y Z
float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

//三角形
void triangleShader() {
	unsigned int VBO;										//  顶点缓冲对象 : 管理由  顶点着色器  创建的内存
	glGenBuffers(GL_ARRAY_BUFFER, &VBO);  // 把新创建的缓冲绑定到 GL_ARRAY_BUFFER 目标上

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // 把定义的 数据 复制到当前绑定 缓冲
}