#pragma once

#include "SimpleRenderer.h"
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window(int width, int height, const char* title);
	~Window();
	void update();
	int shouldClose();
	void processInputs();

private:
	void framebufferSizeCallback(GLFWwindow* window, int width, int height);

	GLFWwindow* m_window;
};