#pragma once

#include "SimpleRenderer.h"
#include "Texture.h"
#include "Mesh.h"

namespace SimpleRenderer {
	class Model {
	public:
		Model(const char* path);
		~Model();
		void addMesh(std::shared_ptr<Mesh> mesh);
		void render();

	private:
		std::vector<std::shared_ptr<Mesh>> m_meshes;
		std::vector<Texture> m_textures;
	};
}