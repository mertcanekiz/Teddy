#ifndef ENGINE_APPLICATION_H_
#define ENGINE_APPLICATION_H_

#include "graphics/opengl.h"
#include <SDL2/SDL.h>
#include <iostream>

class Application {
public:
	Application(int width, int height, const char* title, bool fullscreen);
	~Application();

	int run();

private:
	void input(const SDL_Event& event);
	void update();
	void render();

	bool init();
	bool initSDL();
	bool initOpenGL();

	int width, height;
	const char* title;
	bool fullscreen;

	bool running;
	SDL_Window* window;
	SDL_GLContext glContext;
	SDL_Event event;
};

#endif /* ENGINE_APPLICATION_H_ */
