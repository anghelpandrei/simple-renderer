#pragma once

#include "Camera.h"
#include "Scene.h"
#include "Window.h"

#include <memory>

namespace SimpleRenderer {
	class Application {
	public:
		Application();
		~Application();

		Application(const Application& other) = delete;
		Application& operator=(const Application& other) = delete;

		void createScene();
		void run();

	private:
		std::unique_ptr<Window> m_window;
		std::unique_ptr<Scene> m_scene;
		std::shared_ptr<Camera> m_camera;
	};
}
