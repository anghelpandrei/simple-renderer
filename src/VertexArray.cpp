#include "VertexArray.h"

namespace SimpleRenderer {
	VertexArray::VertexArray(std::shared_ptr<VertexBuffer> vertexBuffer) {
		glGenVertexArrays(1, &m_ID);
		glBindVertexArray(m_ID);
		vertexBuffer->bind();

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, 8 * sizeof(GLfloat), (const void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, false, 8 * sizeof(GLfloat), (const void*)(3 * sizeof(float)));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, false, 8 * sizeof(GLfloat), (const void*)(6 * sizeof(float)));

		m_vertexBuffers.push_back(vertexBuffer);

	}

	VertexArray::~VertexArray() {
		glDeleteVertexArrays(1, &m_ID);
	}

	void VertexArray::setElementBuffer(std::shared_ptr<ElementBuffer> elementBuffer) {
		bind();
		elementBuffer->bind();
		m_elementBuffer = elementBuffer;
	}

	void VertexArray::bind() {
		glBindVertexArray(m_ID);
	}

	void VertexArray::unbind() {
		glBindVertexArray(0);
	}

	GLsizei VertexArray::getCount()
	{
		return m_elementBuffer->getCount();
	}
}