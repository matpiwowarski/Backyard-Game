#include "State.h"

State::State(sf::RenderWindow * window): window(window), quit(false)
{
	sf::Texture house, player_right, player_left, lake, open_house;
	if (!house.loadFromFile("../Assets/house.png") || !player_right.loadFromFile("../Assets/player_right.png")|| 
		!player_left.loadFromFile("../Assets/player_left.png")||!lake.loadFromFile("../Assets/lake.png") 
		|| open_house.loadFromFile("../Assets/open_house.png"))
	{
		// throw exception
	}
	textures.push_back(house);			// 0	
	textures.push_back(player_right);	// 1
	textures.push_back(player_left);	// 2	
	textures.push_back(lake);			// 3
	textures.push_back(open_house);		// 4
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
