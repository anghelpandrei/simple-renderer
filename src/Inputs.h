#pragma once

#include "SimpleRenderer.h"
#include "Window.h"
#include "Scene.h"

namespace SimpleRenderer {
	namespace Inputs {
		void processWindow(Window& window);
		void processScene(Scene& scene);
	}
}
