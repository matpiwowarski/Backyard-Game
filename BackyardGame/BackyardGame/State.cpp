#include "State.h"

State::State(sf::RenderWindow * window): window(window), quit(false)
{
	sf::Texture house;
	if (!house.loadFromFile("house.png"))
	{
		// throw exception
	}
	textures.push_back(house);
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
