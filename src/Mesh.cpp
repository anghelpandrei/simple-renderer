#include "Mesh.h"

namespace SimpleRenderer {
	Mesh::Mesh(std::vector<float> floats, std::vector<GLuint> indices) {
		std::vector<Vertex> vertices;
		for (int i = 0; i < floats.size() / 8; i++) {
			glm::vec3 position(
				floats[8 * i + 0],
				floats[8 * i + 1],
				floats[8 * i + 2]
			);
			glm::vec3 normals(
				floats[8 * i + 3],
				floats[8 * i + 4],
				floats[8 * i + 5]
			);

			glm::vec2 uv(
				floats[8 * i + 6],
				floats[8 * i + 7]
			);

			vertices.emplace_back(position, normals, uv);
		}
		auto vertexBuffer = std::make_shared<VertexBuffer>(vertices);
		m_vertexArray = std::make_unique<VertexArray>(vertexBuffer);
		auto elementBuffer = std::make_shared<ElementBuffer>(indices);
		m_vertexArray->setElementBuffer(elementBuffer);
	}
	Mesh::~Mesh() {

	}
	void Mesh::render() {
		m_vertexArray->bind();
		glDrawElements(GL_TRIANGLES, m_vertexArray->getCount(), GL_UNSIGNED_INT, nullptr);
		m_vertexArray->unbind();
	}
}

