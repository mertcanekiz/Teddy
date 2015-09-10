#ifndef RENDERER_H
#define RENDERER_H

#include "opengl.h"
#include "sprite.h"
#include "shader.h"
#include "texture.h"
#include "../util/transform.h"
#include <SDL2/SDL.h>

class Renderer
{

public:
	Renderer(glm::mat4 projection_matrix = glm::mat4(1.0f));
	~Renderer();

	void add(Sprite* sprite);
	void render();

private:
	glm::mat4 projection_matrix;
	std::vector<Sprite*> sprites;

};

#endif
