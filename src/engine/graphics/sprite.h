#ifndef ENGINE_GRAPHICS_SPRITE_H_
#define ENGINE_GRAPHICS_SPRITE_H_

#include "opengl.h"
#include "texture.h"
#include "shader.h"
#include "../util/transform.h"

class Sprite
{
public:
	Sprite(glm::vec2 size, Texture* texture, Shader* shader);
	~Sprite();

	void init();

	inline Texture* getTexture() { return texture; }
	inline Shader* getShader() { return shader; }
	inline Transform* getTransform() { return transform; }
	inline GLuint getVAOID() const { return vao; }

private:
	GLuint vao, vbo, tbo, ibo;

	std::vector<GLfloat> positions;
	std::vector<GLfloat> texCoords;
	std::vector<GLuint> indices;

	glm::vec2 size;
	Texture* texture;
	Shader* shader;
	Transform* transform;
};

#endif /* ENGINE_GRAPHICS_SPRITE_H_ */
