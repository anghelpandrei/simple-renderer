#pragma once

#include "SimpleRenderer.h"
#include "Texture.h"
#include "Mesh.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

namespace SimpleRenderer {
	class Model {
	public:
		Model(const std::string& path);
		void addMesh(std::unique_ptr<Mesh>&& mesh);
		void render(ShaderProgram& shader);
		inline glm::mat4 getMatrix() const { return glm::mat4(1.0f); }

	private:
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<std::shared_ptr<Texture>> loadMaterialTextures(aiMaterial* mat, aiTextureType type, TextureType textureType);
		std::vector<std::unique_ptr<Mesh>> m_meshes;
		std::vector<std::shared_ptr<Texture>> m_loadedTextures;
		std::string m_directory;
	};
}
