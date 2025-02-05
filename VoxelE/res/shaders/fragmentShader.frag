#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture1;

void main()
{
	FragColor = vec4(TexCoords, 1.0f, 1.0f);
}  