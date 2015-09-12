#ifndef ENGINE_UTIL_TRANSFORM_H_
#define ENGINE_UTIL_TRANSFORM_H_

#include "../graphics/opengl.h"

class Transform {
public:
	Transform(glm::vec2 translation = glm::vec2(), float rotation = 0.0f, glm::vec2 scale = glm::vec2(1.0f))
		: translation(translation),
		  rotation(rotation),
		  scale(scale)
	{
		translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(translation.x, translation.y, 0.0f));
		rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));
		scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scale.x, scale.y, 1.0f));
	}

	inline void setTranslation(const glm::vec2& translation)
	{
		this->translation = translation;
		translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(translation.x, translation.y, 0.0f));
	}

	inline void setRotation(float rotation)
	{
		this->rotation = rotation;
		rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));
	}

	inline void setScale(const glm::vec2& scale)
	{
		this->scale = scale;
		scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scale.x, scale.y, 1.0f));
	}

	inline glm::mat4 getTransformationMatrix()
	{
		return translationMatrix * rotationMatrix * scaleMatrix;
	}

private:
	glm::vec2 translation;
	float rotation;
	glm::vec2 scale;

	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;
};

#endif /* ENGINE_UTIL_TRANSFORM_H_ */
