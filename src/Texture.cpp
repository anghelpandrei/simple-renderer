#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace SimpleRenderer {
	Texture::Texture(const std::string& path, const TextureType type)
		: m_type(type), m_path(path) {
		stbi_set_flip_vertically_on_load(true);

		int channels;
		stbi_uc* data = stbi_load(path.c_str(), &m_width, &m_height, &channels, 0);

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
		release();
	}

	Texture::Texture(Texture&& other) noexcept
		: m_ID(other.m_ID), m_width(other.m_width), m_height(other.m_height), m_type(other.m_type) {
		other.m_ID = 0;
		other.m_width = 0;
		other.m_height = 0;
		other.m_type = TextureType::none;
	}

	Texture& Texture::operator=(Texture&& other) noexcept {
		if (this != &other) {
			release();
			std::swap(m_ID, other.m_ID);
			other.m_width = 0;
			other.m_height = 0;
		}
		return *this;
	}

	void Texture::bind() const {
		glBindTexture(GL_TEXTURE_2D, m_ID);
	}

	void Texture::release() {
		if (m_ID) {
			glDeleteTextures(1, &m_ID);
			m_ID = 0;
		}
	}
}
