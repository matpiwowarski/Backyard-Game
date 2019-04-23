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
	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	this->player.render(this->window);
}
