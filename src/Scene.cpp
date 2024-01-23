#include "Scene.h"
#include <glad/glad.h>

namespace SimpleRenderer {
	Scene::Scene() {

	}

	Scene::~Scene() {

	}

	void Scene::addModel(std::shared_ptr<Model> model)
	{
		m_models.push_back(model);
	}

	void Scene::render() {
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		for (const auto& model : m_models)
			model->render();
	}
}
