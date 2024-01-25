#include "Window.h"

namespace SimpleRenderer {

	Window::Window(int width, int height, const char* title)
		: m_width(width), m_height(height) {

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
		glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
		glfwSetCursorPosCallback(m_window, mouseCallback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "glad failed" << std::endl;
		}

	}

	Window::~Window() {
		glfwDestroyWindow(m_window);
	}

	void Window::bindCamera(std::shared_ptr<Camera> camera) {
		this->camera = camera;
	}

	void Window::update() {
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	int Window::shouldClose() const {
		return glfwWindowShouldClose(m_window);
	}

	void Window::processInputs() {
		if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(m_window, true);

	}

	bool Window::isPressed(const int key) const {
		if (!(glfwGetKey(m_window, key) == GLFW_PRESS))
			return false;
		else
			return true;
	}

	float Window::getAspectRatio() {
		glfwGetWindowSize(m_window, &m_width, &m_height);
		return (float)m_width / m_height;
	}

	void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
		// TODO
		Window* newWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
		newWindow->camera->updateProjection(newWindow->getAspectRatio());
	}

	void Window::mouseCallback(GLFWwindow* window, double xPos, double yPos) {

	}

}