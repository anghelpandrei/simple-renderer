#pragma once

#include "Buffer.h"

#include "glad/glad.h"

#include <memory>

namespace SimpleRenderer {

	class VertexArray {
	public:
		VertexArray(std::unique_ptr<VertexBuffer>&& vertexBuffer, std::unique_ptr<ElementBuffer>&& elementBuffer);
		~VertexArray();
		
		VertexArray(const VertexArray& other) = delete;
		VertexArray& operator=(const VertexArray& other) = delete;
		
		VertexArray(VertexArray&& other) = default;
		VertexArray& operator=(VertexArray&& other) = default;

		void bind() const;
		void unbind() const;
		GLsizei getCount() const;

	private:
		GLuint m_ID;
		std::unique_ptr<VertexBuffer> m_vertexBuffer;
		std::unique_ptr<ElementBuffer> m_elementBuffer;
	};

}