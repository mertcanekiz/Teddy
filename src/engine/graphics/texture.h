#ifndef ENGINE_GRAPHICS_TEXTURE_H_
#define ENGINE_GRAPHICS_TEXTURE_H_

#include "opengl.h"
#include <iostream>

class Texture
{
public:
	Texture(const char* filename);
	~Texture();

	void load();
	void bind() const;
	static void unbind();

private:
	GLuint textureID;
	const char* filename;
};

#endif /* ENGINE_GRAPHICS_TEXTURE_H_ */
