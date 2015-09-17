#include "gameobject.h"

GameObject::GameObject(const glm::vec2& position, const glm::vec2& size)
	: position(position),
	  size(size)
{

}

GameObject::~GameObject()
{
	delete sprite;
	delete transform;
}
