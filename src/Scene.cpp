#include "Scene.h"
#include <glad/glad.h>

namespace SimpleRenderer {
	Scene::Scene() {

	}

	Scene::~Scene() {

	}

	void Scene::addModel(std::shared_ptr<Model> model) {
		m_models.push_back(model);
	}

	void Scene::setModelShader(std::shared_ptr<ShaderProgram> modelShader) {
		m_modelShader = modelShader;
	}

	void Scene::setWaterShader(std::shared_ptr<ShaderProgram> waterShader) {
		m_waterShader = waterShader;
	}

	void Scene::render(const Camera& camera) {
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 p = camera.getProjection();
		glm::mat4 v = camera.getView();

		m_modelShader->use();
		glEnable(GL_DEPTH_TEST);
		for (const auto& model : m_models) {
			glm::mat4 m = model->getMatrix();
			glm::mat4 pvm = p * v * m;
			m_modelShader->setMat4("pvm", pvm);
			model->render();
		}
		m_waterShader->use();

	}
}
