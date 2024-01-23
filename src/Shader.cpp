#include "Shader.h"

Shader::Shader(const char* path, GLenum type) {
	m_ID = glCreateShader(type);
	std::string absolutePath = ROOT_PATH + std::string(path);

	std::ifstream shaderFile;
	shaderFile.open(absolutePath);

	std::stringstream shaderStream;
	shaderStream << shaderFile.rdbuf();

	shaderFile.close();

	std::string shaderCodeString = shaderStream.str();

	const char* shaderCode = shaderCodeString.c_str();
	glShaderSource(m_ID, 1, &shaderCode, NULL);
	glCompileShader(m_ID);

	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(m_ID, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(m_ID, 512, NULL, infoLog);
		std::cout << "ERROR: shader compilation for " << path << std:: endl 
			<< infoLog << std::endl;
	}
	else {
		std::cout << "Shader " << path << " successfully loaded!" << std::endl;
	}

}

Shader::~Shader() {
	glDeleteShader(m_ID);
}

GLuint Shader::getID() const
{
	return m_ID;
}

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath) {
	Shader vertexShader(vertexPath, GL_VERTEX_SHADER);
	Shader fragmentShader(fragmentPath, GL_FRAGMENT_SHADER);

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexShader.getID());
	glAttachShader(m_ID, fragmentShader.getID());
	glLinkProgram(m_ID);

	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
		std::cout << "ERROR: shader linking failed: " << infoLog << std::endl;
	}
	glUseProgram(m_ID);
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(m_ID);
}
