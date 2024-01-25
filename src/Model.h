#pragma once

#include "SimpleRenderer.h"
#include "Texture.h"
#include "Mesh.h"
#include <glm/ext/matrix_float4x4.hpp>

namespace SimpleRenderer {
	class Model {
	public:
		Model(const char* path);
		~Model();
		void addMesh(std::shared_ptr<Mesh> mesh);
		void render();
		glm::mat4 getMatrix();

	private:
		std::vector<std::shared_ptr<Mesh>> m_meshes;
		std::vector<std::shared_ptr<Texture>> m_textures;
	};
}