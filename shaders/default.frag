#version 330 core

in vec3 ourColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float time;

out vec4 FragColor;

void main()
{
	FragColor = vec4(ourColor, 1.0);
}
