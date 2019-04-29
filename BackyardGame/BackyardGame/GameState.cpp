#include "GameState.h"

GameState::GameState(sf::RenderWindow* window): State(window)
{
	house.setPositionAndSize(350, 115, 140, 176);

	house.setTexture(textures[0]);
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
	this->map.update(dt);
	this->house.update(dt);
	this->player.update(dt);
	if (player.getShape().getGlobalBounds().intersects(house.getShape().getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.move(dt, 1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.move(dt, -1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.move(dt, 0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.move(dt, 0.f, -1.f);
		}	
	}
}

void GameState::render(sf::RenderTarget* target)
{
	// the order matters
	this->map.render(this->window);
	this->house.render(this->window);
	this->player.render(this->window);
}
