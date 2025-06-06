#pragma once

#include "Shader.h"

#include "glm/ext/vector_float3.hpp"

namespace SimpleRenderer {

	struct LightAttributes {
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
	};

	struct DirectionalLight {
		glm::vec3 direction;

		LightAttributes attributes;
	};

	struct PointLight {
		glm::vec3 position;

		float constant;
		float linear;
		float quadratic;

		LightAttributes attributes;
		void setUniforms(ShaderProgram& shader) const {
			shader.setVec3f("position", position);
		}
	};

	struct SpotLight {
		glm::vec3 position;
		glm::vec3 direction;

		float cutOff;
		float outerCutOff;

		float constant;
		float linear;
		float quadratic;

		LightAttributes attributes;
	};
}
