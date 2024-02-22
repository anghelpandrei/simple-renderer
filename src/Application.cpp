#include "Application.h"

namespace SimpleRenderer {
	Application::Application() {
		if (!glfwInit()) {
			std::cout << "glfwInit Failed" << std::endl;
		}
		m_window = std::make_unique<Window>(1600, 900, "Simple Renderer");
		createScene();
	}

	Application::~Application() {
		glfwTerminate();
	}

	void Application::createScene() {
		m_scene = std::make_unique<Scene>();
		m_camera = std::make_shared<Camera>
			(glm::vec3(0.0f), glm::vec3(100.0f), glm::vec3(0.0f), glm::vec3(10.0f), glm::vec3(0.0f, 1.0f, 0.0f), 70.0f);
		m_camera->updateProjection(m_window->getAspectRatio());
		m_window->bindCamera(m_camera);
		auto modelShader = std::make_unique<ShaderProgram>("res/shaders/basic.vert", "res/shaders/basic.frag");
		auto waterShader = std::make_unique<ShaderProgram>("res/shaders/basic.vert", "res/shaders/basic.frag");
		m_scene->setModelShader(std::move(modelShader));
		m_scene->setWaterShader(std::move(waterShader));
		auto sponza = std::make_shared<Model>("res/assets/Sponza-master/sponza.obj");
		m_scene->addModel(sponza);
	}

	void Application::run() {
		float timeStep = 0.01f;
		while (!m_window->shouldClose()) {
			// Process the inputs
			Inputs::processWindow(*m_window);
			Inputs::processCamera(*m_window, *m_camera);

			// Render the scene
			m_scene->render(*m_camera);

			// Camera and window update
			m_window->update();
			m_camera->updateCamera(timeStep);

		}
	}
}
