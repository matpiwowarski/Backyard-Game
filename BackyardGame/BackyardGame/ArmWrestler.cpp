#include "ArmWrestler.h"

void ArmWrestler::loadBoardTexture()
{
	if (!boardTexture.loadFromFile("../Assets/board_armwrestling.png"))
	{
		throw; // error;
	}
}

ArmWrestler::ArmWrestler(int level)
{
	this->level = level;
	if (level == 0)
		bet = 1; /// to change
	else if (level == 1)
		bet = 5; /// to change
	else
		bet = 10; /// to change

	loadBoardTexture();
	this->message.setFont(messageFont);
	this->result.setFont(messageFont);
	this->message.setCharacterSize(24);
	this->result.setCharacterSize(24);
	this->message.setFillColor(sf::Color::White);
	this->result.setFillColor(sf::Color::White);
	sf::Vector2f position(250.f, 75.f);
	this->message.setPosition(position);
	boardSprite.setTexture(boardTexture);
	boardSprite.setScale(sf::Vector2f(3.f, 3.f));
	boardSprite.setPosition(sf::Vector2f(125.f, 250.f));
	boardSprite.setScale(sf::Vector2f( 2.f , 2.f));
}

ArmWrestler::~ArmWrestler()
{

}

int ArmWrestler::getLevel() const
{
	return this->level;
}

int ArmWrestler::getBet() const
{
	return this->bet;
}
