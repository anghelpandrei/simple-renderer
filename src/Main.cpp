// simple-renderer.cpp : Defines the entry point for the application.
//

#include "SimpleRenderer.h"

#include "Window.h"
#include "Scene.h"
#include "Inputs.h"
#include "Texture.h"
#include "Model.h"
#include "Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


int main() {
	if (!glfwInit()) {
		std::cout << "glfwInit Failed" << std::endl;
		return -1;
	}

	Window window(1600, 900, "Simple Renderer");
	SimpleRenderer::Scene scene;
	ShaderProgram shaderProgram("src/shaders/basic.vert", "src/shaders/basic.frag");
	auto model = std::make_shared<SimpleRenderer::Model>("res/container.jpg");
	
	std::vector<GLfloat> positions{
		-0.8f, -0.8f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		 0.8f, -0.8f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		 0.8f,  0.8f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.8f,  0.8f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f
	};

	std::vector<GLuint> indices{
		0, 1, 2,
		2, 3, 0
	};

	auto mesh = std::make_shared<SimpleRenderer::Mesh>(positions, indices);
	model->addMesh(mesh);
	scene.addModel(model);

	while (!window.shouldClose()) {
		// input
		SimpleRenderer::Inputs::processWindow(window);

		// render
		scene.render();

		// glfw
		window.update();
		
	}
	glfwTerminate();
	return 0;
}
