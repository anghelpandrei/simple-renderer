#include "Application.h"

#include "Inputs.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>

namespace SimpleRenderer {

	Application::Application() {
		if (!glfwInit()) {
			std::cout << "glfwInit Failed\n";
		}
		m_window = std::make_unique<Window>(1600, 900, "Simple Renderer");
		createScene();
	}

	Application::~Application() {
		glfwTerminate();
	}

	void Application::createScene() {
		m_scene = std::make_unique<Scene>();
		{
			m_camera = std::make_shared<Camera>
				(glm::vec3(0.0f), glm::vec3(1.0f), glm::vec3(0.0f), glm::vec3(10.0f), glm::vec3(0.0f, 1.0f, 0.0f), 70.0f);
			m_camera->updateProjection(m_window->getAspectRatio());
			m_window->bindCamera(m_camera);
		}
		{
			auto modelShader = std::make_unique<ShaderProgram>("res/shaders/phong.vert", "res/shaders/phong.frag");
			auto waterShader = std::make_unique<ShaderProgram>("res/shaders/basic.vert", "res/shaders/basic.frag");
			m_scene->setModelShader(std::move(modelShader));
			m_scene->setWaterShader(std::move(waterShader));
		}
		{
			auto sponza = std::make_shared<Model>("res/assets/Sponza-master/sponza.obj");
			m_scene->addModel(sponza);
		}
		m_scene->init();
	}

	void Application::run() {
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(m_window->getWindow(), true);
		ImGui_ImplOpenGL3_Init("#version 130");
		while (!m_window->shouldClose()) {
			// ImGui
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			ImGui::ShowDemoWindow();
			ImGui::Begin("HelloWorld");
			ImGui::End();
			ImGui::Render();

			// Process the inputs
			Inputs::processWindow(*m_window);
			Inputs::processCamera(*m_window, *m_camera);

			// Render the scene
			m_scene->render(*m_camera);

			// Camera and window update
			m_window->update();
			m_camera->updateCamera(m_timer.getTimeStep());
		}
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
}
