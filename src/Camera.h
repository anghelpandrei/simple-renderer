#pragma once

#include "SimpleRenderer.h"
#include <glm/ext/vector_float3.hpp>

namespace SimpleRenderer {
	class Camera {
	public:
		Camera(glm::vec3 pos, glm::vec3 rot);
		~Camera();

	private:
		glm::vec3 m_pos;
		glm::vec3 m_rot;
	};
}
