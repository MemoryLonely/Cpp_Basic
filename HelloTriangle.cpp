#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

/*
* OpenGL Graphics Pipeline
*
* �����������Vertex Array Object  ---> VAO
* ���㻺�����Vertex Buffer Object ---> VBO
* �����������Element Buffer Object --->EBO (Index Buffer Object ---> IBO)
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

// ��������(VBO) X Y Z
float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

//������
void triangleShader() {
	unsigned int VBO;										//  ���㻺����� : ������  ������ɫ��  �������ڴ�
	glGenBuffers(GL_ARRAY_BUFFER, &VBO);  // ���´����Ļ���󶨵� GL_ARRAY_BUFFER Ŀ����

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // �Ѷ���� ���� ���Ƶ���ǰ�� ����
}