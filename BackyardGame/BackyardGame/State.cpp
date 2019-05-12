#include "State.h"

State::State(sf::RenderWindow * window): window(window), quit(false)
{
	sf::Texture house, player_right, player_left, lake, old_man, red_tree;
	if (!house.loadFromFile("../Assets/house.png") || !player_right.loadFromFile("../Assets/player_right.png")|| 
		!player_left.loadFromFile("../Assets/player_left.png")||!lake.loadFromFile("../Assets/lake.png")
		||!old_man.loadFromFile("../Assets/old_man.png") || !red_tree.loadFromFile("../Assets/red_tree.png"))
	{
		// throw exception
	}
	textures.push_back(house);
	textures.push_back(player_right);
	textures.push_back(player_left);
	textures.push_back(lake);
	textures.push_back(old_man);
	textures.push_back(red_tree);
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
