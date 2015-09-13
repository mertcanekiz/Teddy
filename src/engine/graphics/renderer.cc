#include "renderer.h"

void Renderer::add(Sprite* sprite)
{
	sprites.push_back(sprite);
}

void Renderer::render()
{
	for(Sprite* sprite : sprites)
	{
		sprite->getShader()->bind();
		sprite->getShader()->setUniform("mvp_matrix", projectionMatrix * sprite->getTransform()->getTransformationMatrix());
		sprite->getTexture()->bind();

		glBindVertexArray(sprite->getVAOID());
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
		glBindVertexArray(0);
	}
}