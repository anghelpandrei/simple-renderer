#pragma once

#include "SimpleRenderer.h"
#include <Scene.h>

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SimpleRenderer {

	class Window {
	public:
		Window(int width, int height, const char* title);
		~Window();

		void bindCamera(std::shared_ptr<Camera> camera);
		void update();
		int shouldClose() const;
		void processInputs();
		bool isPressed(const int key) const;
		float getAspectRatio();

		std::shared_ptr<Camera> camera;

	private:
		static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
		static void mouseCallback(GLFWwindow* window, double xPos, double yPos);

		int m_width, m_height;
		GLFWwindow* m_window;
		
	};
}