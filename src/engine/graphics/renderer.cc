#include "renderer.h"

Renderer::Renderer(glm::mat4 projection_matrix)
	: projection_matrix(projection_matrix)
{

}

Renderer::~Renderer()
{
	//for(Sprite* sprite : sprites)
	//	delete sprite;
}

void Renderer::add(Sprite* sprite)
{
	sprites.push_back(sprite);
}

void Renderer::render()
{
	for(Sprite* sprite : sprites)
	{
		sprite->getTransform().setRotation(SDL_GetTicks() / 10.0f);
		sprite->getShader()->bind();
		//sprite->getShader()->setUniform("modelview_matrix", sprite->getTransform().getTransformationMatrix());
		sprite->getShader()->setUniform("mvp_matrix", projection_matrix * sprite->getTransform().getTransformationMatrix());
		sprite->getTexture()->bind();

		glBindVertexArray(sprite->getVAOID());
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
		glBindVertexArray(0);
	}
}
