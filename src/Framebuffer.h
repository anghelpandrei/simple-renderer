#pragma once

#include "SimpleRenderer.h"
#include <glad/glad.h>

namespace SimpleRenderer {
	class Framebuffer {
	public:
		Framebuffer();
		~Framebuffer();
		Framebuffer(const Framebuffer& other) = delete;
		Framebuffer& operator=(const Framebuffer& other) = delete;
		void bind();
		void unbind();

	private:
		GLuint m_ID;
	};
}
