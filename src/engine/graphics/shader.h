#ifndef ENGINE_GRAPHICS_SHADER_H_
#define ENGINE_GRAPHICS_SHADER_H_

#include "opengl.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	void load();
	void bind() const;

	void setUniform(const char* name, float value);
	void setUniform(const char* name, const glm::vec2& vector);
	void setUniform(const char* name, const glm::vec3& vector);
	void setUniform(const char* name, const glm::mat4& matrix);

private:
	GLint getUniformLocation(const char* name);

	GLuint programID;
	const char* vertexPath;
	const char* fragmentPath;
	std::unordered_map<std::string, GLint> uniforms;
};

#endif /* ENGINE_GRAPHICS_SHADER_H_ */
