#pragma once
#include "SimpleRenderer.h"
#include <Model.h>

namespace SimpleRenderer {
	class Scene {
	public:
		Scene();
		~Scene();
		void addModel(std::shared_ptr<Model> model);
		void render();

	private:
		std::vector<std::shared_ptr<Model>> m_models;
	};
}