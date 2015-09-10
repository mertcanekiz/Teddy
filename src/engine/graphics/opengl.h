#ifndef OPENGL_H
#define OPENGL_H

#if defined __APPLE__
#include <OpenGL/gl3.h>
#define NOGLEW
#else
#include <GL/glew.h>
#endif

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#endif
