#pragma once

#include "SimpleRenderer.h"
#include <glad/glad.h>
#include "VertexArray.h"
#include "Buffer.h"
#include "Texture.h"
#include "Shader.h"

namespace SimpleRenderer {
	class Mesh {
	public:
		Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices, const std::vector<std::shared_ptr<Texture>>& textures);
		~Mesh() = default;
		
		Mesh(const Mesh& other) = delete;
		Mesh& operator=(const Mesh& other) = delete;
		
		Mesh(Mesh&& other) noexcept = default;
		Mesh& operator=(Mesh&& other) noexcept = default;
		
		void render(ShaderProgram& shader) const;

	private:
		std::unique_ptr<VertexArray> m_vertexArray;
		std::vector<std::shared_ptr<Texture>> m_textures;
	};
}
