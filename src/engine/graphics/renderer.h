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
	
};

#endif /* ENGINE_GRAPHICS_RENDERER_H_ */