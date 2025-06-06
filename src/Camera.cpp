#include "Camera.h"
#include "glm/ext/matrix_clip_space.hpp"

namespace SimpleRenderer {

	Camera::Camera(const glm::vec3& pos, const glm::vec3& speed, const glm::vec3& rot, const glm::vec3& rotSpeed, const glm::vec3& worldUp, const float fov)
		: m_pos(pos), m_speed(speed), m_rot(glm::radians(rot)), m_rotSpeed(glm::radians(rotSpeed)), m_worldUp(worldUp), m_fov(fov) {
	}

	void Camera::updateCamera(double timeStep) {
		m_pos += static_cast<float>(timeStep) * m_speed * m_acc;
		m_rot += static_cast<float>(timeStep) * m_rotAcc;
		m_acc = glm::vec3(0.0f);
		m_rotAcc = glm::vec3(0.0f);
		if (m_rot.x > 1.5f)
			m_rot.x = 1.5f;
		else if (m_rot.x < -1.5f)
			m_rot.x = -1.5f;
		updateVectors();
	}

	void Camera::updateCameraMouse(double mouseX, double mouseY) {
		m_rotAcc.x = static_cast<float>(mouseY) * m_rotSpeed.x;
		m_rotAcc.y = static_cast<float>(mouseX) * m_rotSpeed.y;
		
	}

	void Camera::updateCameraKeyboard(int keyboardX, int keyboardY, int keyboardZ) {
		switch (keyboardX) {
		case KeyboardDirection::None: break;
		case KeyboardDirection::Forward: m_acc += glm::normalize(m_front - glm::dot(m_worldUp, m_front) * m_worldUp); break;
		case KeyboardDirection::Backward: m_acc -= glm::normalize(m_front - glm::dot(m_worldUp, m_front) * m_worldUp); break;
		default: break;
		}

		switch (keyboardZ) {
		case KeyboardDirection::None: break;
		case KeyboardDirection::Left: m_acc -= m_right; break;
		case KeyboardDirection::Right: m_acc += m_right; break;
		default: break;
		}

		switch (keyboardY) {
		case KeyboardDirection::None: m_acc.y = 0.0f; break;
		case KeyboardDirection::Up: m_acc.y = m_worldUp.y; break;
		case KeyboardDirection::Down: m_acc.y = -m_worldUp.y; break;
		default: break;
		}
	}

	void Camera::updateProjection(float aspectRatio) {
		m_projection = glm::perspective(glm::radians(m_fov), aspectRatio, m_zNear, m_zFar);
	}

	void Camera::updateVectors() {
		m_front = glm::normalize(glm::vec3(
			cos(m_rot.y) * cos(m_rot.x),
			sin(m_rot.x),
			sin(m_rot.y) * cos(m_rot.x)
		));
		m_right = glm::normalize(glm::cross(m_front, m_worldUp));
		m_up = glm::normalize(glm::cross(m_right, m_front));
	}
}