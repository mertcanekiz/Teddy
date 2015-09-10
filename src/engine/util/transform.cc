#include "transform.h"

Transform::Transform(glm::vec2 translation, float rotation, glm::vec2 scale)
	: translation(translation),
	  rotation(rotation),
	  scale(scale)
{
	translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(translation.x, translation.y, 0.0f));
	rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));
	scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scale.x, scale.y, 1.0f));
}

void Transform::setTranslation(glm::vec2 translation)
{
	this->translation = translation;
	translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(translation.x, translation.y, 0.0f));
}

void Transform::setRotation(float rotation)
{
	this->rotation = rotation;
	rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));
}

void Transform::setScale(glm::vec2 scale)
{
	this->scale = scale;
	scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scale.x, scale.y, 1.0f));
}

glm::mat4 Transform::getTransformationMatrix()
{
	return translationMatrix * rotationMatrix * scaleMatrix;
}
