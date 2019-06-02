#pragma once
#include "Entity.h"
#include <random>
#include <chrono>
#include <ctime>
class Dice 
{
private:
	bool isChosenToReroll = false;
	int choice;
	sf::Texture diceTexture;
	sf::Sprite diceSprite;
public:
	Dice();
	~Dice();

	//getters/setters
	void setDiceTexture(const sf::Texture texture);
	void setDiceSprite(const sf::Sprite sprite);
	void setIsChosenToReroll(const bool & choice);

	bool getIsChosenToReroll();
	int getChoice();
	sf::Texture & getDiceTexture();
	sf::Sprite & getDiceSprite();

	//methods
	void randomChoice();
};
