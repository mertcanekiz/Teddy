#version 330 core

out vec4 fragColor;

in DATA
{
	vec2 texCoord;
} fs_in;

uniform sampler2D textureSampler;

void main()
{
	fragColor = texture(textureSampler, fs_in.texCoord);
}
