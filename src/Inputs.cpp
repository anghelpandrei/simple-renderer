#include "Inputs.h"

namespace SimpleRenderer {
	namespace Inputs {
		void processWindow(Window& window) {
			window.processInputs();
		}

		void Inputs::processCamera(const Window& window, Camera& camera) {
			int xDir = KeyboardDirection::None;
			int yDir = KeyboardDirection::None;
			int zDir = KeyboardDirection::None;

			if (window.isPressed(GLFW_KEY_W))
				xDir += KeyboardDirection::Forward;
			if (window.isPressed(GLFW_KEY_S))
				xDir += KeyboardDirection::Backward;
			if (window.isPressed(GLFW_KEY_SPACE))
				yDir += KeyboardDirection::Up;
			if (window.isPressed(GLFW_KEY_LEFT_SHIFT))
				yDir += KeyboardDirection::Down;
			if (window.isPressed(GLFW_KEY_A))
				zDir += KeyboardDirection::Left;
			if (window.isPressed(GLFW_KEY_D))
				zDir += KeyboardDirection::Right;

			camera.updateCameraKeyboard(xDir, yDir, zDir);
		}
	}
}

