#include "Model.h"

#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"

#include <iostream>

namespace SimpleRenderer {

	Model::Model(const std::string& path) {
		Assimp::Importer importer;
		auto scene = importer.ReadFile(path, aiProcess_Triangulate
										   | aiProcess_GenSmoothNormals
										   | aiProcess_FlipUVs
										   | aiProcess_CalcTangentSpace);
		if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
			std::cout << "Error loading scene: " << importer.GetErrorString() << '\n';
        }
        else {
            m_directory = path.substr(0, path.find_last_of('/'));
            processNode(scene->mRootNode, scene);
        }
	}

	void Model::addMesh(std::unique_ptr<Mesh>&& mesh) {
		m_meshes.push_back(std::move(mesh));
	}

	void Model::render(ShaderProgram& shader) {
        for (const auto& mesh : m_meshes) {
			mesh->render(shader);
		}
	}

	void Model::processNode(aiNode* node, const aiScene* scene) {
		for (unsigned int i = 0; i < node->mNumMeshes; i++) {
			aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
			m_meshes.emplace_back(std::make_unique<Mesh>(processMesh(mesh, scene)));
		}
		for (unsigned int i = 0; i < node->mNumChildren; i++) {
			processNode(node->mChildren[i], scene);
		}
	}
	
	Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene) {
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        std::vector<std::shared_ptr<Texture>> textures;

        for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
            
            glm::vec3 position(
                mesh->mVertices[i].x,
                mesh->mVertices[i].y,
                mesh->mVertices[i].z
            );
            
            glm::vec3 normal(0.0f);
            if (mesh->HasNormals()) {
                normal.x = mesh->mNormals[i].x;
                normal.y = mesh->mNormals[i].y;
                normal.z = mesh->mNormals[i].z;
            }

            glm::vec2 uv(0.0f);
            glm::vec3 tangent(0.0f);
            glm::vec3 bitangent(0.0f);
            if (mesh->mTextureCoords[0]) {
                uv.x = mesh->mTextureCoords[0][i].x;
                uv.y = mesh->mTextureCoords[0][i].y;
                
                tangent.x = mesh->mTangents[i].x;
                tangent.y = mesh->mTangents[i].y;
                tangent.z = mesh->mTangents[i].z;
                
                bitangent.x = mesh->mBitangents[i].x;
                bitangent.y = mesh->mBitangents[i].y;
                bitangent.z = mesh->mBitangents[i].z;
            }
            vertices.emplace_back(position, normal, uv);
        }
        
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++) {
                indices.push_back(face.mIndices[j]);
            }
        }

        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
        // we assume a convention for sampler names in the shaders. Each diffuse texture should be named
        // as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER. 
        // Same applies to other texture as the following list summarizes:
        // diffuse: texture_diffuseN
        // specular: texture_specularN
        // normal: texture_normalN

        // 1. diffuse maps
        std::vector<std::shared_ptr<Texture>> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, TextureType::diffuse);
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
        // 2. specular maps
        std::vector<std::shared_ptr<Texture>> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, TextureType::specular);
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
        // 3. normal maps
        std::vector<std::shared_ptr<Texture>> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, TextureType::normal);
        textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
        // 4. height maps
        std::vector<std::shared_ptr<Texture>> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, TextureType::height);
        textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

        // return a mesh object created from the extracted mesh data
        return Mesh(vertices, indices, textures);
	}

    std::vector<std::shared_ptr<Texture>> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, TextureType textureType) {
        std::vector<std::shared_ptr<Texture>> textures;
        for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
            aiString str;
            mat->GetTexture(type, i, &str);
            std::string path = m_directory + '/' + std::string(str.C_Str());
            bool skip = false;
            for (size_t i = 0; i < m_loadedTextures.size(); i++) {
                if (m_loadedTextures[i]->getPath() == path) {
                    skip = true;
                    textures.push_back(m_loadedTextures[i]);
                    break;
                }
            }
            if (!skip) {
                auto texture = std::make_shared<Texture>(path, textureType);
                textures.push_back(texture);
                m_loadedTextures.push_back(texture);
            }
        }
        return textures;
    }

}