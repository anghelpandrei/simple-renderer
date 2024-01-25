#pragma once

#include "SimpleRenderer.h"
#include <glad/glad.h>
#include <glm/ext/matrix_float4x4.hpp>

namespace SimpleRenderer {

	class Shader {
	public:
		Shader(const char* path, GLenum type);
		~Shader();
		GLuint getID() const;

	private:
		GLuint m_ID;
	};

	class ShaderProgram {
	public:
		ShaderProgram(const char* vertexPath, const char* fragmentPath);
		~ShaderProgram();

		void use();
		void setInteger(const GLchar* name, const int value);
		void setFloat(const GLchar* name, const float value);
		void setVec3f(const GLchar* name, const glm::vec3& vector);
		void setMat4(const GLchar* name, const glm::mat4& matrix);

	private:
		GLuint m_ID;
	};

}
