#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include"MainOpenGL.h"

using namespace std;  // 引用命名空间

const unsigned int SCR_WIDTH = 800;  // 窗口程序的宽度
const unsigned int SCR_HEIGHT = 800; // 窗口程序的高度

// 顶点着色器
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

// 片元着色器
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int makeWin() {
	glfwInit();	//初始化 GLFW

	//配置 GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //设置 GLFW 上下文 主版本号(Major) 为 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //设置 GLFW 上下文 次版本号(Minor) 为 3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //使用 核心模式

	//创建窗口对象
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//将窗口的上下文设置为当前线程的主上下文
	glfwMakeContextCurrent(window); 
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//初始化 GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	/*----------------------------------------------------- build and compile shader ---------------------------------------------------------------
	  构建并编译着色器  https://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/
	  顶点数组对象：Vertex Array Object  ---> VAO
	  顶点缓冲对象：Vertex Buffer Object--->VBO
	  索引缓冲对象：Element Buffer Object--->EBO (Index Buffer Object ---> IBO)

	  Anton Gerdelan的渲染第一个三角形教程  http://antongerdelan.net/opengl/hellotriangle.html
	  Alexander Overvoorde的渲染第一个三角形教程  https://open.gl/drawing
	  顶点缓冲对象的一些深入探讨   http://antongerdelan.net/opengl/vertexbuffers.html
	  调试的教程  https://learnopengl.com/In-Practice/Debugging
	---------------------------------------------------------------------------------------------------------------------------------------------------*/
	//  顶点着色器 ---->  把一个单独的顶点作为输入
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);            // 创建一个 着色器对象
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);   // 把 着色器源码 附加到 着色器对象
	glCompileShader(vertexShader);		 // 编译着色器对象

	//检测着色器编译错误
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// 片段着色器 ----> 片段着色器所做的是计算像素最后的颜色输出
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);			  // 创建一个 着色器对象
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);   // 把 着色器源码 附加到 着色器对象
	glCompileShader(fragmentShader);    // 编译着色器对象

	//检测着色器编译错误
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//链接 着色器 程序对象
	int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//检查链接错误
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// 删除着色器
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//定义不重复的顶点坐标(X, Y, Z, 其中 Z 表示深度)
	float vertices[] = {
		0.5f,  0.5f, 0.0f,   // 0
		0.5f, -0.5f, 0.0f,  // 1
		-0.5f, -0.5f, 0.0f, // 2
		-0.5f, 0.5f, 0.0f,  // 3
		0.0f, 0.0f, 0.0f,	  // 4
		0.0f, 0.5f, 0.0f,	  // 5
		0.0f, -0.5f, 0.0f,  // 6
	};
	//图形的坐标点以顺时针方向连接
	unsigned int indices[] = {
		//0, 1, 3,  // 第一个三角形的坐标索引
		//1, 2, 3,   // 第二个三角形的坐标索引

		3, 5, 4,
		4, 6, 2
	};

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);  // 设置 顶点数组对象
	glGenBuffers(1, &VBO);			 // 设置 顶点缓冲对象
	glGenBuffers(1, &EBO);			 // 设置 索引缓冲对象
	glBindVertexArray(VAO);         // 绑定 顶点数组对象

	// 复制顶点数组到缓冲中供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, VBO);   // 绑定缓冲区
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // 在当前绑定的缓冲区对象中分配内存, 并将数据初始化在内存中
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);  //绑定 索引缓冲对象 到缓冲区
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); //使用当前绑定的索引缓冲对象中的索引进行绘制

	// 设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);  // 告诉OpenGL该如何解析顶点数据（应用到逐个顶点属性上）
	glEnableVertexAttribArray(0); //启用 顶点属性数组

	glBindBuffer(GL_ARRAY_BUFFER, 0);  // 绑定缓冲区
	glBindVertexArray(0);							// 绑定顶点数组对象
	//----------------------------------------------------- build and compile shader ---------------------------------------------------------------
	
	//设置渲染的窗口尺寸
	glViewport(0, 0, 800, 600);

	//创建渲染循环
	while (!glfwWindowShouldClose(window)) {  //每次循环的开始前检查一次 GLFW 是否被要求退出

		processInput(window);								//检查有事件触发

		// 渲染
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //设置清空屏幕所用的颜色
		glClear(GL_COLOR_BUFFER_BIT); //清除颜色缓冲之后，整个颜色缓冲都会被填充为glClearColor里所设置的颜色

		//绘制图形
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window); //交换颜色缓冲
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

//定义 窗口尺寸
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
