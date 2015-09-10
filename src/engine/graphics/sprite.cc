#include "sprite.h"

Sprite::Sprite(glm::vec2 size, Texture* texture, Shader* shader)
	: size(size), texture(texture), shader(shader)
{
	float halfWidth = (float) size.x;
	float halfHeight = (float) size.y;
	positions =
	{
		-halfWidth, -halfHeight, 0.0f,
		 halfWidth, -halfHeight, 0.0f,
		 halfWidth,  halfHeight, 0.0f,
		-halfWidth,  halfHeight, 0.0f
	};

	std::cout << halfWidth << std::endl;

	texCoords =
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	indices =
	{
		0, 1, 2,
		2, 3, 0
	};
}

Sprite::~Sprite()
{
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &tbo);
	glDeleteBuffers(1, &ibo);

	glDeleteVertexArrays(1, &vao);
}

void Sprite::init()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
		std::cout << "bound" << std::endl;

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof positions[0] * positions.size(), &positions[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glGenBuffers(1, &tbo);
		glBindBuffer(GL_ARRAY_BUFFER, tbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof texCoords[0] * texCoords.size(), &texCoords[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof indices[0] * indices.size(), &indices[0], GL_STATIC_DRAW);

	shader->load();
	texture->load();
	glBindVertexArray(0);

}
