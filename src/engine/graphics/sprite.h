#ifndef SPRITE_H
#define SPRITE_H

#include "texture.h"
#include "shader.h"
#include "../util/transform.h"

class Sprite
{
public:
	Sprite(glm::vec2 size = glm::vec2(2.0f), Texture* texture = NULL, Shader* shader = NULL);
	~Sprite();

	void init();

	inline Texture* getTexture() { return texture; }
	inline Shader* getShader() { return shader; }
	inline Transform& getTransform() { return transform; }
	inline GLuint getVAOID() const { return vao; }

private:
	GLuint vao, vbo, tbo, ibo;

	std::vector<GLfloat> positions;
	std::vector<GLfloat> texCoords;
	std::vector<GLuint> indices;

	glm::vec2 size;
	Texture* texture;
	Shader* shader;

	Transform transform;

};

#endif
