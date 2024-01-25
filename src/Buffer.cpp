#include "Buffer.h"

namespace SimpleRenderer {

	VertexBuffer::VertexBuffer(std::vector<Vertex> vertices) {
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
	}

	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &m_ID);
	}

	void VertexBuffer::bind() {
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}

	void VertexBuffer::unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


	ElementBuffer::ElementBuffer(std::vector<GLuint> indices)
		: m_count((GLsizei)indices.size()) {
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
	}

	ElementBuffer::~ElementBuffer() {
		glDeleteBuffers(1, &m_ID);
	}
	
	void ElementBuffer::bind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}

	void ElementBuffer::unbind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	GLsizei ElementBuffer::getCount() const {
		return m_count;
	}
}


