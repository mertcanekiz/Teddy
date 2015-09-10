#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../graphics/opengl.h"

class Transform
{
public:
	Transform(glm::vec2 translation = glm::vec2(0.0f), float rotation = 0.0f, glm::vec2 scale = glm::vec2(1.0f));
	~Transform() {}

	void setTranslation(glm::vec2 translation);
	void setRotation(float rotation);
	void setScale(glm::vec2 scale);

	glm::mat4 getTransformationMatrix();

private:
	float rotation;
	glm::vec2 scale;
	glm::vec2 translation;

	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;
};

#endif
