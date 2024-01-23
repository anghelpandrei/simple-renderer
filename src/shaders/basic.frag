#version 430 core

in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D texture0;

void main() {
	//FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	FragColor = texture(texture0, TexCoords);
}