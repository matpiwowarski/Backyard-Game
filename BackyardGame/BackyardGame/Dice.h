#pragma once
#include "Entity.h"
#include <random>
#include <chrono>
#include <ctime>
class Dice 
{
private:
	int choice;
	sf::Texture diceTexture;
	sf::Sprite diceSprite;
public:
	Dice();
	~Dice();

	//getters/setters
	void setDiceTexture(const sf::Texture texture);
	void setDiceSprite(const sf::Sprite sprite);
	int getChoice();
	sf::Texture & getDiceTexture();
	sf::Sprite & getDiceSprite();


	void randomChoice();
};

