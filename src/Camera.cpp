#include "Camera.h"

namespace SimpleRenderer {

	Camera::Camera(glm::vec3 pos, glm::vec3 rot) : m_pos(pos), m_rot(rot) {
	}

	Camera::~Camera()
	{
	}

}