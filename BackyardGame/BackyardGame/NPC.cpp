#include "NPC.h"

NPC::NPC()
{
	if (!this->messageFont.loadFromFile("../Assets/fonts/CarterOne.ttf")) // PressStart2P-Regular.ttf
	{
		throw; // error;
	}
	else
	{
		
	}
}

NPC::~NPC()
{
}

void NPC::loadCursorTexture()
{
	if (!cursorTexture.loadFromFile("../Assets/cursor.png"))
	{
		throw; // error
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
