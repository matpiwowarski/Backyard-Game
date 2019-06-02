#include "NPC.h"

NPC::NPC()
{
	try
	{
		if (!this->messageFont.loadFromFile("../Assets/fonts/CarterOne.ttf")) // PressStart2P-Regular.ttf
			throw - 1;
	}
	catch (int)
	{
		std::cout << "Problem with font loading";
	}
}

NPC::~NPC()
{
}

void NPC::loadCursorTexture()
{

	try
	{
		if (!cursorTexture.loadFromFile("../Assets/cursor.png"))
			throw - 1;
	}
	catch (int)
	{
		std::cout << "Problem with cursor texture loading";;
	}
}

sf::Text NPC::getNPCMessage() const
{
	return this->message;
}

sf::Text NPC::getNPCResultText()
{
	return this->result;
}

sf::Font NPC::getMessageFont() const
{
	return messageFont;
}

sf::Text NPC::getEndGameMessage() 
{
	this->message.setScale(sf::Vector2f(3, 3));
	this->message.setPosition(sf::Vector2f(250, 215));
	this->message.setString(" THE END ");
	return message;
}

sf::Sprite NPC::getBoardSprite() const
{
	return boardSprite;
}

sf::Sprite NPC::getNPCChoiceSprite() const
{
	return this->choiceSprite;
}
sf::Texture NPC::getNPCChoiceTexture() const
{
	return this->choiceTexture;
}
//to change later, maybe by using templates

sf::Sprite NPC::getCursorSprite() const
{
	return cursorSprite;
}

void NPC::notEnoughCoins()
{
	this->message.setString("You don't have enough coins");
}
