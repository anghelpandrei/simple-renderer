#pragma once

#include "GLFW/glfw3.h"

namespace SimpleRenderer {

	class Timer {
	public:
		double getTimeStep() {
			m_currentTime = glfwGetTime();
			m_timeStep = m_currentTime - m_lastTime;
			m_lastTime = m_currentTime;
			return m_timeStep;
		}

	private:
		double m_lastTime = glfwGetTime();
		double m_currentTime = 0.0;
		double m_timeStep = 0.0;
	};
}
