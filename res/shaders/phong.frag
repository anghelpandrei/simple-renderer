#version 410 core

struct PointLight {
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D texture_diffuse1;
uniform vec3 cameraPos;
uniform PointLight pointLights[4];

void main() {
	float test = pointLights[0].constant;
	vec4 color = texture(texture_diffuse1, TexCoords);
	FragColor = color + constant;
}
