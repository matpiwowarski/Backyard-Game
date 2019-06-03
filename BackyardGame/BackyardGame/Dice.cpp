#include "Dice.h"

Dice::Dice()
{
}

Dice::~Dice()
{
}

//getters/setters

void  Dice::setDiceTexture(const sf::Texture & texture)
{
	diceTexture = texture;
}

void Dice::setDiceSprite(const sf::Sprite & sprite)
{
	diceSprite = sprite;
}

void Dice::setIsChosenToReroll(const bool & choice)
{
	this->isChosenToReroll = choice;
}


bool Dice::getIsChosenToReroll()
{
	return this->isChosenToReroll;
}

int Dice::getChoice()
{
	return this->choice;
}

sf::Texture & Dice::getDiceTexture() 
{
	return this->diceTexture;
}

sf::Sprite & Dice::getDiceSprite()
{
	return this->diceSprite;
}


void Dice::randomChoice()
{
	std::default_random_engine engine;
	std::uniform_real_distribution<double> distribution;
	auto czas = std::chrono::system_clock::now();
	auto interval = czas.time_since_epoch();
	engine.seed(interval.count());

	int random = distribution(engine) * 100;
	this->choice = random % 6;
}

