#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

out DATA
{
	vec2 texCoord;
} vs_out;

uniform mat4 modelview_matrix;
uniform mat4 mvp_matrix = mat4(1.0);
uniform mat4 projection_matrix = mat4(1.0);

void main()
{
	gl_Position = mvp_matrix * vec4(position, 1.0);
	vs_out.texCoord = texCoord;
}
