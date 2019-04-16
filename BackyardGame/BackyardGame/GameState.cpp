#include "GameState.h"

GameState::GameState(sf::RenderWindow* window): State(window)
{

}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "THE END" << std::endl;
}

void GameState::updateKeybinds(const double & dt)
{
	this->checkQuit();
}

void GameState::update(const double& dt)
{
	this->updateKeybinds(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		std::cout << "X pressed" << std::endl;
	}
}

void GameState::render(sf::RenderTarget* target)
{
}
