#include "Mesh.h"

namespace SimpleRenderer {
	Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices, const std::vector<std::shared_ptr<Texture>>& textures)
		: m_textures(textures) {
		m_vertexArray = std::make_unique<VertexArray>(
			std::move(std::make_unique<VertexBuffer>(vertices)),
			std::move(std::make_unique<ElementBuffer>(indices))
		);
	}

	void Mesh::render(ShaderProgram& shader) const {
		for (const auto& texture : m_textures) {
			std::string uniformName;
			if (texture->getType() == TextureType::diffuse) {
				glActiveTexture(GL_TEXTURE0);
				uniformName = "texture_diffuse1";
				shader.setInteger(uniformName.c_str(), 0);
				texture->bind();
			}
		}
		m_vertexArray->bind();
		glDrawElements(GL_TRIANGLES, m_vertexArray->getCount(), GL_UNSIGNED_INT, nullptr);
	}
}

