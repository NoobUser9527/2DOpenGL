#include "GLAD/glad.h"
#include "GLFW/glfw3.h"

#include <stdio.h>
#include <iostream>



#include "Engine.h"


static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int main()
{
	glfwSetErrorCallback(glfw_error_callback);

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// 创建窗口上下文
	GLFWwindow* window = glfwCreateWindow(750, 750, "Let's Chess!", NULL, NULL);
	if (window == nullptr)
	{
		printf("创建 GLFW 窗口失败");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);// 开启垂直同步

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("初始化GLAD失败");
		return -1;
	}

	// 启用混合(让图片可以透明)
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);




	Engine engine;

	glm::vec2 sign = glm::vec2((float)SPEED);


	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		// Engine

		engine.Clear();
		engine.Draw();

		
		


		

		glfwPollEvents();
		glfwSwapBuffers(window);
	}


	

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}