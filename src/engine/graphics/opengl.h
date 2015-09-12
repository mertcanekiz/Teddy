#ifndef ENGINE_GRAPHICS_OPENGL_H_
#define ENGINE_GRAPHICS_OPENGL_H_

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
	#define NOGLEW
#else
	#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#endif /* ENGINE_GRAPHICS_OPENGL_H_ */
