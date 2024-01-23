#include "Window.h"

Window::Window(int width, int height, const char* title) {

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (m_window == NULL) {
		std::cout << "Failed to create window" << std::endl;
	}
	glfwMakeContextCurrent(m_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad failed" << std::endl;
	}

}

Window::~Window() {
	glfwDestroyWindow(m_window);
}

void Window::update() {
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

int Window::shouldClose() {
	return glfwWindowShouldClose(m_window);
}

void Window::processInputs() {
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, true);

}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
