#pragma once

#include "glad/glad.h"
#include "glm/ext/vector_float3.hpp"
#include "glm/ext/vector_float2.hpp"

#include <vector>

namespace SimpleRenderer {

	struct Vertex {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 uv;
        Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 uv)
            : position(position), normal(normal), uv(uv) {}
	};

	class VertexBuffer {
	public:
		VertexBuffer(std::vector<Vertex> vertices);
		~VertexBuffer();

		VertexBuffer(const VertexBuffer& other) = delete;
		VertexBuffer& operator=(const VertexBuffer& other) = delete;
		
		VertexBuffer(VertexBuffer&& other) = default;
		VertexBuffer& operator=(VertexBuffer&& other) = default;

		void bind() const;
		void unbind() const;

	private:
		GLuint m_ID;
	};

	class ElementBuffer {
	public:
		ElementBuffer(std::vector<GLuint> indices);
		~ElementBuffer();

		ElementBuffer(const ElementBuffer& other) = delete;
		ElementBuffer& operator=(const ElementBuffer& other) = delete;
		
		ElementBuffer(ElementBuffer&& other) = default;
		ElementBuffer& operator=(ElementBuffer&& other) = default;

		void bind() const;
		void unbind() const;
		GLsizei getCount() const;

	private:
		GLuint m_ID;
		GLsizei m_count;
	};
}
