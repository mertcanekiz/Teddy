#include "testgame.h"

TestGame::TestGame()
	: shader("res/shaders/basic.vert", "res/shaders/basic.frag"),
	  texture("res/textures/teddy.png")
{
	ortho = glm::ortho(0.0f, 480.0f, 0.0f, 270.0f);
}

TestGame::~TestGame()
{
	delete renderer;
	delete sprite;
}

void TestGame::init()
{
	renderer = new Renderer(ortho);
	sprite = new Sprite(glm::vec2(32, 48), &texture, &shader);
	sprite->getTransform().setTranslation(glm::vec2(100, 100));
	sprite->init();
	renderer->add(sprite);
}

void TestGame::input(const SDL_Event& event)
{

}

void TestGame::update()
{
	sprite->getTransform().setRotation(SDL_GetTicks() / 10.0f);
}

void TestGame::render()
{
	renderer->render();
}
