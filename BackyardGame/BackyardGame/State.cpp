#include "State.h"

State::State()
{

}

State::State(sf::RenderWindow * window) : window(window), quit(false)
{
	sf::Texture house, player_right, player_left, lake, old_man, red_tree, open_house, fence_up, fence_left, fence_right, fence_down;
	if (!house.loadFromFile("../Assets/house.png") || !player_right.loadFromFile("../Assets/player_right.png") ||
		!player_left.loadFromFile("../Assets/player_left.png") || !lake.loadFromFile("../Assets/lake.png")
		|| !old_man.loadFromFile("../Assets/old_man.png") || !red_tree.loadFromFile("../Assets/red_tree.png")
		|| !open_house.loadFromFile("../Assets/open_house.png")||!fence_up.loadFromFile("../Assets/fence_up.png")
		|| !fence_left.loadFromFile("../Assets/fence_left.png") || !fence_right.loadFromFile("../Assets/fence_right.png")
		|| !fence_down.loadFromFile("../Assets/fence_down.png"))
	{
		// throw exception
	}
	textures.push_back(house);			// 0
	textures.push_back(player_right);	// 1	
	textures.push_back(player_left);	// 2
	textures.push_back(lake);			// 3
	textures.push_back(old_man);		// 4
	textures.push_back(red_tree);		// 5
	textures.push_back(open_house);		// 6
	textures.push_back(fence_up);		// 7
	textures.push_back(fence_down);		// 8
	textures.push_back(fence_left);		// 9
	textures.push_back(fence_right);	// 10
}

State::~State()
{
}

void State::setEnetredHouse(bool enteredHouse)
{
	this->enteredHouse = enteredHouse;
}

void State::setEnteredGarden(bool enteredGarden)
{
	this->enteredGarden = enteredGarden;
}

void State::setBackToBackyard(bool backToBackyard)
{
	this->backToBackyard = backToBackyard;
}

void State::checkQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}

bool State::hasEnteredHouse() const
{
	return enteredHouse;
}

bool State::hasEnteredGarden() const
{
	return enteredGarden;
}

bool State::hasBackToBackyard() const
{
	return backToBackyard;
}

bool State::getQuit() const
{
	return this->quit;
}
