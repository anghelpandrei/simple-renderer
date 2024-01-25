#include "Camera.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace SimpleRenderer {

	Camera::Camera(const glm::vec3& pos, const glm::vec3& speed, const glm::vec3& rot, const glm::vec3& rotSpeed, const glm::vec3& worldUp, const float fov)
		: m_pos(pos), m_speed(speed), m_rot(glm::radians(rot)), m_rotSpeed(glm::radians(rotSpeed)), m_worldUp(worldUp), m_fov(fov) {
	}

	Camera::~Camera() {

	}

	void Camera::updateCamera(float timeStep) {
		m_pos += timeStep * m_speed * m_speedDir;
		updateVectors();
	}

	void Camera::updateCameraMouse(float timeStep, float mouseX, float mouseY) {
		m_rot.x += mouseY * m_rotSpeed.x;
		m_rot.y += mouseX * m_rotSpeed.y;
		if (m_rot.x > 89.0f)
			m_rot.x = 89.0f;
		else if (m_rot.x < -89.0f)
			m_rot.x = -89.0f;
	}

	void Camera::updateCameraKeyboard(int keyboardX, int keyboardY, int keyboardZ) {
		switch (keyboardX) {
		case KeyboardDirection::None: m_speedDir.x = 0.0f; break;
		case KeyboardDirection::Forward: m_speedDir.x = 1.0f; break;
		case KeyboardDirection::Backward: m_speedDir.x = -1.0f; break;
		default: break;
		}

		switch (keyboardY) {
		case KeyboardDirection::None: m_speedDir.y = 0.0f; break;
		case KeyboardDirection::Up: m_speedDir.y = 1.0f; break;
		case KeyboardDirection::Down: m_speedDir.y = -1.0f; break;
		default: break;
		}

		switch (keyboardZ) {
		case KeyboardDirection::None: m_speedDir.z = 0.0f; break;
		case KeyboardDirection::Left: m_speedDir.z = -1.0f; break;
		case KeyboardDirection::Right: m_speedDir.z = 1.0f; break;
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
		m_up = glm::normalize(glm::cross(glm::cross(m_front, m_worldUp), m_front));
	}

	glm::mat4 Camera::getView() const {
		return glm::lookAt(m_pos, m_pos + m_front, m_up);
	}

	glm::mat4 Camera::getProjection() const	{
		return m_projection;
	}

}