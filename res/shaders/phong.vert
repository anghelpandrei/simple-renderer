#version 410 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

uniform mat4 PV;
uniform mat4 M;
uniform mat4 itM;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;

void main() {
	vec4 FragPos4 = M * vec4(aPosition, 1.0);
	FragPos = FragPos.xyz;
	Normal = mat3(itM) * aNormal;
	TexCoords = aTexCoords;
	gl_Position = PV * FragPos4;
}
