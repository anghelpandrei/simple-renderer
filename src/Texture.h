#pragma once

#include "glad/glad.h"

#include <string>
#include <string_view>

namespace SimpleRenderer {

	enum class TextureType {
		none, diffuse, specular, normal, height
	};

	class Texture {
	public:
		Texture(std::string_view path, const TextureType type);
		~Texture();

        Texture(const Texture& other) = delete;
		Texture& operator=(const Texture& other) = delete;
		
        Texture(Texture&& other) noexcept;
		Texture& operator=(Texture&& other) noexcept;

		void bind() const;
		inline TextureType getType() const { return m_type; }
		inline std::string getPath() const { return m_path; }


	private:
		void release();
		int m_width, m_height;
		GLuint m_ID;
		TextureType m_type;
		std::string m_path;
	};

}
