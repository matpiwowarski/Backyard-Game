#include "State.h"

State::State(sf::RenderWindow * window): window(window), quit(false)
{
	sf::Texture house, player_right, player_left, lake;
	if (!house.loadFromFile("../Assets/house.png") || !player_right.loadFromFile("../Assets/player_right.png")|| 
		!player_left.loadFromFile("../Assets/player_left.png")||!lake.loadFromFile("../Assets/lake.png"))
	{
		// throw exception
	}
	textures.push_back(house);
	textures.push_back(player_right);
	textures.push_back(player_left);
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
