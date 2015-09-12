#include "shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
	: vertexPath(vertexPath), fragmentPath(fragmentPath)
{
	programID = 0;
}

Shader::~Shader()
{
	glDeleteProgram(programID);
}


void Shader::setUniform(const char* name, float value)
{
	glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform(const char* name, const glm::vec2& vector)
{
	glUniform2f(getUniformLocation(name), vector.x, vector.y);
}

void Shader::setUniform(const char* name, const glm::vec3& vector)
{
	glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
}

void Shader::setUniform(const char* name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

GLint Shader::getUniformLocation(const char* name)
{
	auto it = uniforms.find(std::string(name));
	GLint location;

	if(it != uniforms.end())
	{
		location = it->second;
	}
	else
	{
		location = glGetUniformLocation(programID, name);

		if(location == -1)
			std::cerr << "Could not find uniform: " << name << std::endl;

		uniforms[name] = location;
	}

	return location;
}

void Shader::bind() const
{
	glUseProgram(programID);
}

void Shader::load()
{
	// Create the shaders
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string vertexShaderCode;
	std::ifstream vertexShaderStream(vertexPath, std::ios::in);
	if(vertexShaderStream.is_open())
	{
	std::string Line = "";
	while(getline(vertexShaderStream, Line))
		vertexShaderCode += "\n" + Line;
	vertexShaderStream.close();
	}

	// Read the Fragment Shader code from the file
	std::string fragmentShaderCode;
	std::ifstream fragmentShaderStream(fragmentPath, std::ios::in);
	if(fragmentShaderStream.is_open()){
	std::string Line = "";
	while(getline(fragmentShaderStream, Line))
		fragmentShaderCode += "\n" + Line;
	fragmentShaderStream.close();
	}

	GLint result = GL_FALSE;
	int infoLogLength;

	// Compile Vertex Shader
	std::cout << "Compiling shader: " << vertexPath << std::endl;
	char const * vertexSourcePointer = vertexShaderCode.c_str();
	glShaderSource(vertexShaderID, 1, &vertexSourcePointer , NULL);
	glCompileShader(vertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
	std::vector<char> vertexShaderErrorMessage(infoLogLength);
	glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
	if(result == GL_FALSE)
		std::cerr << &vertexShaderErrorMessage[0] << std::endl;

	// Compile Fragment Shader
	std::cout << "Compiling shader: " << fragmentPath << std::endl;
	char const * fragmentSourcePointer = fragmentShaderCode.c_str();
	glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer , NULL);
	glCompileShader(fragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
	std::vector<char> fragmentShaderErrorMessage(infoLogLength);
	glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
	if(result == GL_FALSE)
		std::cerr << &fragmentShaderErrorMessage[0] << std::endl;

	// Link the program
	std::cout << "Linking program" << std::endl;
	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

	// Check the program
	glGetProgramiv(programID, GL_LINK_STATUS, &result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
	std::vector<char> programErrorMessage( std::max(infoLogLength, int(1)) );
	glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
	if(result == GL_FALSE)
		std::cerr << &programErrorMessage[0] << std::endl;


	glValidateProgram(programID);
	glGetProgramiv(programID, GL_VALIDATE_STATUS, &result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
	std::vector<char> validateErrorMessage( std::max(infoLogLength, int(1)) );
	glGetProgramInfoLog(programID, infoLogLength, NULL, &validateErrorMessage[0]);
	if(result == GL_FALSE)
		std::cerr << "Could not validate shader program: " << &validateErrorMessage[0] << std::endl;

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

