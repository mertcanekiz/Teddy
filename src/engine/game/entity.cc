#include "entity.h"

Entity::Entity(const glm::vec2& position, const glm::vec2& size, const Sprite& sprite, const Transform& transform)
	: position(position),
	  size(size),
	  sprite(sprite),
	  transform(transform)
{

}

Entity::~Entity()
{
}
