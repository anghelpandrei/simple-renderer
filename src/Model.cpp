#include "Model.h"

namespace SimpleRenderer {

	Model::Model(const char* path) {
		m_textures.emplace_back(path);
	}

	Model::~Model() {

	}

	void Model::addMesh(std::shared_ptr<Mesh> mesh) {
		m_meshes.push_back(mesh);
	}

	void Model::render() {
		for (const auto& mesh : m_meshes) {
			m_textures[0].bind();
			mesh->render();
		}
	}

}