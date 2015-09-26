#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../graphics/opengl.h"
#include <SDL2/SDL.h>

#include "../graphics/sprite.h"
#include "../util/transform.h"

class GameObject
{
public:
	GameObject(const glm::vec2& position, const glm::vec2& size);
	virtual ~GameObject();

	const glm::vec2& getPosition() const { return position; }
	const glm::vec2& getSize() const { return size; }
	const glm::vec2& getVelocity() const { return velocity; }
	const glm::vec2& getAcceleration() const { return acceleration; }

	Sprite* getSprite() const { return sprite; }
	Transform* getTransform() const { return transform; }

	void setPosition(const glm::vec2& position) { this->position = position; }
	void setSize(const glm::vec2& size) { this->size = size; }
	void setVelocity(const glm::vec2& velocity) { this->velocity = velocity; }
	void setAcceleration(const glm::vec2& acceleration) { this->acceleration = acceleration; }

	virtual void init() = 0;
	virtual void input(const SDL_Event& event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;

protected:
	
	glm::vec2 position;
	glm::vec2 size;
	glm::vec2 velocity;
	glm::vec2 acceleration;

	Sprite* sprite;
	Transform* transform;
};

#endif
