#pragma once

#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>

namespace SimpleRenderer {

	enum KeyboardDirection {
		None = 0,
		Forward = 1,
		Backward = -1,
		Up = 2,
		Down = -2,
		Left = -3,
		Right = 3
	};

	class Camera {
	public:
		Camera(const glm::vec3& pos, const glm::vec3& speed, const glm::vec3& rot, const glm::vec3& rotSpeed, const glm::vec3& worldUp, const float fov);

		void updateCamera(float timeStep);
		void updateCameraMouse(float mouseX, float mouseY);
		void updateCameraKeyboard(int keyboardX, int keyboardY, int keyboardZ);
		void updateProjection(float aspectRatio);
		void updateVectors();
		glm::mat4 getView() const;
		glm::mat4 getProjection() const;

	private:
		glm::vec3 m_pos;
		glm::vec3 m_speed;
		glm::vec3 m_acc = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 m_rot; // x = pitch, y = yaw, z = roll
		glm::vec3 m_rotSpeed;
		glm::vec3 m_rotAcc = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 m_worldUp;
		glm::vec3 m_front;
		glm::vec3 m_right;
		glm::vec3 m_up;
		glm::mat4 m_projection;
		float m_fov;
		float m_zNear = 1.f;
		float m_zFar = 2000.0f;
	};
}
