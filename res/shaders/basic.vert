#version 410 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

uniform mat4 PVM;

out vec2 TexCoords;

void main() {
	TexCoords = aTexCoords;

	gl_Position = PVM * vec4(aPosition, 1.0f);
}
