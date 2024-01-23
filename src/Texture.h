#pragma once

#include "SimpleRenderer.h"
#include <glad/glad.h>

namespace SimpleRenderer {
	class Texture {
	public:
		Texture(const char* path);
		~Texture();
		void bind();
	private:
		int m_width, m_height;
		GLuint m_ID;
	};

}
