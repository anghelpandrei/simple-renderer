#include "VertexArray.h"

namespace SimpleRenderer {
	VertexArray::VertexArray(std::unique_ptr<VertexBuffer>&& vertexBuffer, std::unique_ptr<ElementBuffer>&& elementBuffer)
		: m_vertexBuffer(std::move(vertexBuffer)), m_elementBuffer(std::move(elementBuffer)) {
		glGenVertexArrays(1, &m_ID);
		glBindVertexArray(m_ID);
		m_vertexBuffer->bind();

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, 8 * sizeof(GLfloat), (const void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, false, 8 * sizeof(GLfloat), (const void*)(3 * sizeof(float)));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, false, 8 * sizeof(GLfloat), (const void*)(6 * sizeof(float)));

		m_elementBuffer->bind();

	}

	VertexArray::~VertexArray() {
		glDeleteVertexArrays(1, &m_ID);
	}

	void VertexArray::bind() const {
		glBindVertexArray(m_ID);
	}

	void VertexArray::unbind() const {
		glBindVertexArray(0);
	}

	GLsizei VertexArray::getCount() const {
		return m_elementBuffer->getCount();
	}
}