#pragma once

#include "Model.h"
#include "Camera.h"
#include "Shader.h"
#include "Light.h"

namespace SimpleRenderer {

	class Scene {
	public:
		void addModel(const std::shared_ptr<Model> model);
		void setModelShader(std::unique_ptr<ShaderProgram>&& modelShader);
		void setWaterShader(std::unique_ptr<ShaderProgram>&& waterShader);
		void init();
		void render(const Camera& camera);
		
	private:
		std::vector<std::shared_ptr<Model>> m_models;
		std::vector<PointLight> m_pointLights;
		std::unique_ptr<ShaderProgram> m_modelShader;
		std::unique_ptr<ShaderProgram> m_waterShader;
	};
}