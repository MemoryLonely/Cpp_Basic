#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include"MainOpenGL.h"

using namespace std;  // ���������ռ�

const unsigned int SCR_WIDTH = 800;  // ���ڳ���Ŀ��
const unsigned int SCR_HEIGHT = 800; // ���ڳ���ĸ߶�

// ������ɫ��
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

// ƬԪ��ɫ��
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int makeWin() {
	glfwInit();	//��ʼ�� GLFW

	//���� GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //���� GLFW ������ ���汾��(Major) Ϊ 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //���� GLFW ������ �ΰ汾��(Minor) Ϊ 3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //ʹ�� ����ģʽ

	//�������ڶ���
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//�����ڵ�����������Ϊ��ǰ�̵߳���������
	glfwMakeContextCurrent(window); 
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//��ʼ�� GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	/*----------------------------------------------------- build and compile shader ---------------------------------------------------------------
	  ������������ɫ��  https://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/
	  �����������Vertex Array Object  ---> VAO
	  ���㻺�����Vertex Buffer Object--->VBO
	  �����������Element Buffer Object--->EBO (Index Buffer Object ---> IBO)

	  Anton Gerdelan����Ⱦ��һ�������ν̳�  http://antongerdelan.net/opengl/hellotriangle.html
	  Alexander Overvoorde����Ⱦ��һ�������ν̳�  https://open.gl/drawing
	  ���㻺������һЩ����̽��   http://antongerdelan.net/opengl/vertexbuffers.html
	  ���ԵĽ̳�  https://learnopengl.com/In-Practice/Debugging
	---------------------------------------------------------------------------------------------------------------------------------------------------*/
	//  ������ɫ�� ---->  ��һ�������Ķ�����Ϊ����
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);            // ����һ�� ��ɫ������
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);   // �� ��ɫ��Դ�� ���ӵ� ��ɫ������
	glCompileShader(vertexShader);		 // ������ɫ������

	//�����ɫ���������
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Ƭ����ɫ�� ----> Ƭ����ɫ���������Ǽ�������������ɫ���
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);			  // ����һ�� ��ɫ������
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);   // �� ��ɫ��Դ�� ���ӵ� ��ɫ������
	glCompileShader(fragmentShader);    // ������ɫ������

	//�����ɫ���������
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//���� ��ɫ�� �������
	int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//������Ӵ���
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// ɾ����ɫ��
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//���岻�ظ��Ķ�������(X, Y, Z, ���� Z ��ʾ���)
	float vertices[] = {
		0.5f,  0.5f, 0.0f,   // 0
		0.5f, -0.5f, 0.0f,  // 1
		-0.5f, -0.5f, 0.0f, // 2
		-0.5f, 0.5f, 0.0f,  // 3
		0.0f, 0.0f, 0.0f,	  // 4
		0.0f, 0.5f, 0.0f,	  // 5
		0.0f, -0.5f, 0.0f,  // 6
	};
	//ͼ�ε��������˳ʱ�뷽������
	unsigned int indices[] = {
		//0, 1, 3,  // ��һ�������ε���������
		//1, 2, 3,   // �ڶ��������ε���������

		3, 5, 4,
		4, 6, 2
	};

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);  // ���� �����������
	glGenBuffers(1, &VBO);			 // ���� ���㻺�����
	glGenBuffers(1, &EBO);			 // ���� �����������
	glBindVertexArray(VAO);         // �� �����������

	// ���ƶ������鵽�����й�OpenGLʹ��
	glBindBuffer(GL_ARRAY_BUFFER, VBO);   // �󶨻�����
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // �ڵ�ǰ�󶨵Ļ����������з����ڴ�, �������ݳ�ʼ�����ڴ���
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);  //�� ����������� ��������
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); //ʹ�õ�ǰ�󶨵�������������е��������л���

	// ���ö�������ָ��
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);  // ����OpenGL����ν����������ݣ�Ӧ�õ�������������ϣ�
	glEnableVertexAttribArray(0); //���� ������������

	glBindBuffer(GL_ARRAY_BUFFER, 0);  // �󶨻�����
	glBindVertexArray(0);							// �󶨶����������
	//----------------------------------------------------- build and compile shader ---------------------------------------------------------------
	
	//������Ⱦ�Ĵ��ڳߴ�
	glViewport(0, 0, 800, 600);

	//������Ⱦѭ��
	while (!glfwWindowShouldClose(window)) {  //ÿ��ѭ���Ŀ�ʼǰ���һ�� GLFW �Ƿ�Ҫ���˳�

		processInput(window);								//������¼�����

		// ��Ⱦ
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //���������Ļ���õ���ɫ
		glClear(GL_COLOR_BUFFER_BIT); //�����ɫ����֮��������ɫ���嶼�ᱻ���ΪglClearColor�������õ���ɫ

		//����ͼ��
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window); //������ɫ����
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

//���� ���ڳߴ�
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
