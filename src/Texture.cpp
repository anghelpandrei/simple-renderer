#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace SimpleRenderer {
	Texture::Texture(const char* path) {

		stbi_set_flip_vertically_on_load(true);

		int channels;

		std::string absolutePath = ROOT_PATH + std::string(path);
		const char* newPath = absolutePath.c_str();

		stbi_uc* data = stbi_load(newPath, &m_width, &m_height, &channels, 0);

		if (data) {
			std::cout << "Texture " << path << " loaded successfully" << std::endl;
		}
		else {
			std::cout << "Texture " << path << " failed to load" << std::endl;
		}

		GLenum format;
		switch (channels) {
		case 1:
			format = GL_RED;
			break;
		case 2:
			format = GL_RG;
			break;
		case 3:
			format = GL_RGB;
			break;
		case 4:
			format = GL_RGBA;
			break;
		default:
			format = GL_RED;
			break;
		}
		glGenTextures(1, &m_ID);
		glBindTexture(GL_TEXTURE_2D, m_ID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, m_width, m_height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture::~Texture() {
		glDeleteTextures(1, &m_ID);
	}

	void Texture::bind() {
		glBindTexture(GL_TEXTURE_2D, m_ID);
	}
}
