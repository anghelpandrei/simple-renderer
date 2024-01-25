#pragma once
#include "SimpleRenderer.h"
#include <Model.h>
#include <Camera.h>
#include <Shader.h>

namespace SimpleRenderer {
	class Scene {
	public:
		Scene();
		~Scene();
		void addModel(const std::shared_ptr<Model> model);
		void setModelShader(std::shared_ptr<ShaderProgram> modelShader);
		void setWaterShader(std::shared_ptr<ShaderProgram> waterShader);
		void render(const Camera& camera);

	private:
		std::vector<std::shared_ptr<Model>> m_models;
		std::shared_ptr<ShaderProgram> m_modelShader;
		std::shared_ptr<ShaderProgram> m_waterShader;
	};
}