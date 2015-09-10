#ifndef APPLICATION_H
#define APPLICATION_H

#include "graphics/opengl.h"
#include <SDL2/SDL.h>
#include <iostream>

#include "../game/testgame.h"

class Application
{

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

	SDL_Window* window;
	SDL_GLContext glContext;
	SDL_Event event;
	bool running;

	TestGame game;

};

#endif
