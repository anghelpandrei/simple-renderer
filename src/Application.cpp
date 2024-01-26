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
		m_camera = std::make_shared<Camera>(glm::vec3(0.0f), glm::vec3(1.0f), glm::vec3(0.0f), glm::vec3(10.0f), glm::vec3(0.0f, 1.0f, 0.0f), 70.0f);
		m_camera->updateProjection(m_window->getAspectRatio());
		m_window->bindCamera(m_camera);
		auto modelShader = std::make_shared<ShaderProgram>("src/shaders/basic.vert", "src/shaders/basic.frag");
		auto waterShader = std::make_shared<ShaderProgram>("src/shaders/basic.vert", "src/shaders/basic.frag");
		m_scene->setModelShader(modelShader);
		m_scene->setWaterShader(waterShader);
		auto model = std::make_shared<Model>("res/container.jpg");

		std::vector<GLfloat> screen{
			-0.8f, -8.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			 0.8f, -0.8f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.8f,  0.8f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.8f,  0.8f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f
		};

		std::vector<GLfloat> positions{
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f
		};

		std::vector<GLuint> indicesPlane{
			0, 1, 2,
			2, 3, 0
		};

		std::vector<GLuint> indices{
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35
		};

		auto mesh = std::make_shared<Mesh>(positions, indices);
		model->addMesh(mesh);
		m_scene->addModel(model);
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
