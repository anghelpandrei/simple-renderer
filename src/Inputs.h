#pragma once

#include "Camera.h"
#include "Window.h"

namespace SimpleRenderer {
	namespace Inputs {
		void processWindow(Window& window);
		void processCamera(const Window& window, Camera& camera);
	}
}
