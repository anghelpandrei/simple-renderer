#pragma once

#include "Camera.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <memory>

namespace SimpleRenderer {

	class Window {
	public:
		Window(int width, int height, const char* title);
		~Window();

		Window(const Window& other) = delete;
		Window& operator&(const Window& other) = delete;

		void bindCamera(std::shared_ptr<Camera> camera);
		void update();
		int shouldClose() const;
		void processInputs();
		bool isPressed(const int key) const;
		float getAspectRatio();
		GLFWwindow* getWindow() const { return m_window; }

		std::shared_ptr<Camera> camera;

		double lastX{ 0.0 }, lastY{ 0.0 };

	private:
		static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
		static void mouseCallback(GLFWwindow* window, double xPos, double yPos);

		int m_width, m_height;
		GLFWwindow* m_window;
		
	};
}