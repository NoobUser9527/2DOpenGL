#version 330 core
out vec4 FragColor;

in vec2 vTexCoord;

uniform sampler2D tex;

void main()
{
	FragColor = texture(tex, vTexCoord);
	//FragColor = mix(texture(texBoard, vTexCoord),texture(texBoard, vTexCoord), 0.5);
}