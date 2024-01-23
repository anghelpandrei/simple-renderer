#pragma once

#include "SimpleRenderer.h"
#include "Buffer.h"
#include <glad/glad.h>

namespace SimpleRenderer {

	class VertexArray {
	public:
		VertexArray(std::shared_ptr<VertexBuffer> vertexBuffer);
		~VertexArray();
		void setElementBuffer(std::shared_ptr<ElementBuffer> elementBuffer);
		void bind();
		void unbind();
		GLsizei getCount();

	private:
		GLuint m_ID;
		std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
		std::shared_ptr<ElementBuffer> m_elementBuffer;
	};

}