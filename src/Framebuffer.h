#pragma once

#include "SimpleRenderer.h"
#include <glad/glad.h>

namespace SimpleRenderer {
	class Framebuffer {
	public:
		Framebuffer();
		~Framebuffer();
		void bind();
		void unbind();

	private:
		GLuint m_ID;
	};
}
