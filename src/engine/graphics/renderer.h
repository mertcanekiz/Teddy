#ifndef ENGINE_GRAPHICS_RENDERER_H_
#define ENGINE_GRAPHICS_RENDERER_H_ 

#include "opengl.h"
#include "sprite.h"
#include <vector>

class Renderer
{
	
public:
	Renderer(const glm::mat4& projectionMatrix)
		: projectionMatrix(projectionMatrix) {}
	~Renderer();

	void add(Sprite* sprite);
	void render();
	
private:
	std::vector<Sprite*> sprites;
	glm::mat4 projectionMatrix;
};

#endif /* ENGINE_GRAPHICS_RENDERER_H_ */