#include "application.h"

Application::Application(int width, int height, const char* title, bool fullscreen)
	: width(width),
	  height(height),
	  title(title),
	  fullscreen(fullscreen)
{
	window = NULL;
	running = false;
}

Application::~Application()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int Application::run()
{
	if(!init())
		return -1;

	game.init();

	running = true;

	while(running)
	{
		while(SDL_PollEvent(&event))
			input(event);
		update();
		render();
	}

	return 0;
}

void Application::input(const SDL_Event& event)
{
	if(event.type == SDL_QUIT)
		running = false;
}

void Application::update()
{

}

void Application::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	game.render();
	SDL_GL_SwapWindow(window);
}

bool Application::init()
{
	return initSDL() && initOpenGL();
}

bool Application::initSDL()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	window = SDL_CreateWindow(title,
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					width,
					height,
					SDL_WINDOW_OPENGL);

	if(window == NULL)
	{
		std::cerr << "Could not create SDL window: " << SDL_GetError() << std::endl;
		return false;
	}

	glContext = SDL_GL_CreateContext(window);

	if(window == NULL)
	{
		std::cerr << "Could not create OpenGL context: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

bool Application::initOpenGL()
{
	#ifndef NOGLEW
	glewExperimental = true;
	GLenum glewResult = glewInit();
	if(glewResult != GLEW_OK)
	{
		std::cerr << "Could not initialize GLEW: " << glewGetErrorString(glewResult) << std::endl;
		return false;
	}
	#endif

	std::cout << glGetString(GL_VERSION) << std::endl;

	glClearColor(0, 0.5, 0.5, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glFrontFace(GL_CW);

	return true;
}
