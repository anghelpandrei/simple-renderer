#pragma once

#include "SimpleRenderer.h"
#include <glad/glad.h>
#include "VertexArray.h"
#include "Buffer.h"

namespace SimpleRenderer {

	class Mesh {
	public:
		Mesh(std::vector<GLfloat> vertices, std::vector<GLuint> positions);
		~Mesh();
		void render();

	private:
		std::unique_ptr<VertexArray> m_vertexArray;
	};

}
