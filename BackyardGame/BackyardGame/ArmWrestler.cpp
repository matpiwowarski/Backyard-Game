#include "ArmWrestler.h"

ArmWrestler::ArmWrestler()
{
	this->cursorIndex = 9;

	loadCursorTexture();
	cursorSprite.setTexture(cursorTexture);
	cursorSprite.setScale(sf::Vector2f(0.15, 0.15));
	updateCursorSpritePosition();

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
	boardSprite.setScale(sf::Vector2f(2.f, 2.f));
}

void ArmWrestler::updateCursorSpritePosition()
{
	if (cursorIndex == 0)
		cursorSprite.setPosition(sf::Vector2f(190.f, 320.f));
	else if (cursorIndex == 1)
		cursorSprite.setPosition(sf::Vector2f(211.f, 320.f));
	else if (cursorIndex == 2)
		cursorSprite.setPosition(sf::Vector2f(231.f, 320.f));
	else if (cursorIndex == 3)
		cursorSprite.setPosition(sf::Vector2f(253.f, 320.f));
	else if (cursorIndex == 4)
		cursorSprite.setPosition(sf::Vector2f(274.f, 320.f));
	else if (cursorIndex == 5)
		cursorSprite.setPosition(sf::Vector2f(295.f, 320.f));
	else if (cursorIndex == 6)
		cursorSprite.setPosition(sf::Vector2f(316.f, 320.f));
	else if (cursorIndex == 7)
		cursorSprite.setPosition(sf::Vector2f(337.f, 320.f));
	else if (cursorIndex == 8)
		cursorSprite.setPosition(sf::Vector2f(364.f, 320.f));
	else if (cursorIndex == 9)
		cursorSprite.setPosition(sf::Vector2f(387.f, 320.f));
	else if (cursorIndex == 10)
		cursorSprite.setPosition(sf::Vector2f(400.f, 320.f));
	else if (cursorIndex == 11)
		cursorSprite.setPosition(sf::Vector2f(421.f, 320.f));
	else if (cursorIndex == 12)
		cursorSprite.setPosition(sf::Vector2f(442.f, 320.f));
	else if (cursorIndex == 13)
		cursorSprite.setPosition(sf::Vector2f(463.f, 320.f));
	else if (cursorIndex == 14)
		cursorSprite.setPosition(sf::Vector2f(484.f, 320.f));
	else if (cursorIndex == 15)
		cursorSprite.setPosition(sf::Vector2f(505.f, 320.f));
	else if (cursorIndex == 16)
		cursorSprite.setPosition(sf::Vector2f(526.f, 320.f));
	else if (cursorIndex == 17)
		cursorSprite.setPosition(sf::Vector2f(546.f, 320.f));
	else if (cursorIndex == 18)
		cursorSprite.setPosition(sf::Vector2f(568.f, 320.f));
	else if (cursorIndex == 19)
		cursorSprite.setPosition(sf::Vector2f(585.f, 320.f));
}

ArmWrestler & ArmWrestler::getInstance()
{
	static ArmWrestler instance;
	return instance;
}

void ArmWrestler::loadBoardTexture()
{
	if (!boardTexture.loadFromFile("../Assets/board_armwrestling.png"))
	{
		throw; // error;
	}
}

void ArmWrestler::setCursorIndex(int index)
{
	this->cursorIndex = index;
}

int ArmWrestler::getCursorIndex() const
{
	return cursorIndex;
}
