#ifndef TESTGAME_H
#define TESTGAME_H

#include <SDL2/SDL.h>

#include "../engine/graphics/opengl.h"
#include "../engine/graphics/shader.h"
#include "../engine/graphics/texture.h"
#include "../engine/graphics/sprite.h"
#include "../engine/graphics/renderer.h"
#include "../engine/util/transform.h"

class TestGame
{
public:
	TestGame();
	~TestGame();

	void init();
	void input(const SDL_Event& event);
	void update();
	void render();

private:
	Shader shader;
	Texture texture;
	Sprite* sprite;
	Renderer* renderer;

	glm::mat4 ortho;

};

#endif
