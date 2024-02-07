#pragma once

#include "SimpleRenderer.h"
#include <glad/glad.h>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float2.hpp>

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
		void bind();
		void unbind();

	private:
		GLuint m_ID;
	};

	class ElementBuffer {
	public:
		ElementBuffer(std::vector<GLuint> indices);
		~ElementBuffer();
		void bind();
		void unbind();
		GLsizei getCount() const;

	private:
		GLuint m_ID;
		GLsizei m_count;
	};
}
