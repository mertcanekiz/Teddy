#ifndef TEXTURE_H
#define TEXTURE_H 

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

#endif