#include "State.h"

State::State(sf::RenderWindow * window): window(window), quit(false)
{
	sf::Texture house, player, lake;
	if (!house.loadFromFile("../Assets/house.png") || !player.loadFromFile("../Assets/player.png")||!lake.loadFromFile("../Assets/lake.png"))
	{
		// throw exception
	}
	textures.push_back(house);
	textures.push_back(player);
	textures.push_back(lake);
}

State::~State()
{
}

void State::checkQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}

bool State::getQuit() const
{
	return this->quit;
}
