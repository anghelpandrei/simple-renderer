#pragma once

#include "SimpleRenderer.h"
#include <glad/glad.h>

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
private:
	GLuint m_ID;
};
