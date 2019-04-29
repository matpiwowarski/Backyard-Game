#include "State.h"

State::State(sf::RenderWindow * window): window(window), quit(false)
{
	sf::Texture house, player;
	if (!house.loadFromFile("../Assets/house.png") || !player.loadFromFile("../Assets/player.png"))
	{
		// throw exception
	}
	textures.push_back(house);
	textures.push_back(player);
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
