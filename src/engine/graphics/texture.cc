#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const char* filename)
	: filename(filename)
{
	textureID = 0;
}

Texture::~Texture()
{
	glDeleteTextures(1, &textureID);
}

void Texture::load()
{
	int width, height, comp;
	stbi_set_flip_vertically_on_load(1);
	unsigned char* image = stbi_load(filename, &width, &height, &comp, STBI_rgb_alpha);

	if(image == NULL)
	{
		std::cerr << "Could not load image: " << filename << std::endl;
		exit(1);
	}

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(image);
}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

