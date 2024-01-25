#pragma once

#include "SimpleRenderer.h"

#include "Window.h"
#include "Scene.h"
#include "Inputs.h"
#include "Texture.h"
#include "Model.h"
#include "Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace SimpleRenderer {
	class Application {
	public:
		Application();
		~Application();
		void createScene();
		void run();

	private:
		std::unique_ptr<Window> m_window;
		std::unique_ptr<Scene> m_scene;
		std::shared_ptr<Camera> m_camera;
	};
}
