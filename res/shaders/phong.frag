#version 410 core

struct PointLight {
	vec3 position;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D texture_diffuse1;

void main() {
	vec4 color = texture(texture_diffuse1, TexCoords);
	FragColor = color;
}
