#include "NPC.h"

NPC::NPC()
{
	if (!this->messageFont.loadFromFile("../Assets/fonts/CarterOne.ttf")) // PressStart2P-Regular.ttf
	{
		throw; // error;
	}
	else
	{
		loadBoardTexture();
		loadCursorTexture();
		this->message.setFont(messageFont);
		this->result.setFont(messageFont);
		this->message.setCharacterSize(24);
		this->result.setCharacterSize(24);
		this->message.setFillColor(sf::Color::Black);
		this->result.setFillColor(sf::Color::Black);
		sf::Vector2f position(290.f, 450.f);
		this->message.setPosition(position);
		boardSprite.setTexture(boardTexture);
		boardSprite.setScale(sf::Vector2f(3.f, 3.f));
		boardSprite.setPosition(sf::Vector2f(230.f, 252.f));
		cursorSprite.setTexture(cursorTexture);
		cursorSprite.setScale(sf::Vector2f(1 / 8.f, 1 / 8.f));
		updateCursorSpritePosition();
	}
}

NPC::~NPC()
{
}

void NPC::randomChoice()
{
	std::default_random_engine engine;
	std::uniform_real_distribution<double> distribution;
	auto czas = std::chrono::system_clock::now();
	auto interval = czas.time_since_epoch();
	engine.seed(interval.count());

	int random = distribution(engine) * 100;
	this->choice = random % 3;
}

void NPC::uploadNPCChoiceTexture()
{
	if (!choiceTexture.loadFromFile("../Assets/" + std::to_string(choice) + ".png"))
	{
		throw; // error
	}
}

void NPC::loadCursorTexture()
{
	if (!cursorTexture.loadFromFile("../Assets/cursor.png"))
	{
		throw; // error
	}
}

void NPC::loadBoardTexture()
{
	if (!boardTexture.loadFromFile("../Assets/board_rps.png"))
	{
	throw; // error;
	}
}

void NPC::updateCursorSpritePosition()
{
	if (cursorIndex == 0)
	{
		cursorSprite.setPosition(sf::Vector2f(275.f, 325.f));
	}
	else if (cursorIndex == 1)
	{
		cursorSprite.setPosition(sf::Vector2f(390.f, 325.f));
	}
	else if (cursorIndex == 2)
	{
		cursorSprite.setPosition(sf::Vector2f(490.f, 325.f));
	}
}

sf::Text NPC::getNPCMessage() const
{
	return this->message;
}

sf::Text NPC::getNPCResultText()
{
	sf::Vector2f position(340.f, 500.f);
	this->result.setPosition(position);
	if(cursorIndex == 0 && this->choice == 0)
		this->result.setString("IT'S A DRAW");
	if(cursorIndex == 1 && this->choice == 1)
		this->result.setString("IT'S A DRAW");
	if (cursorIndex == 2 && this->choice == 2)
		this->result.setString("IT'S A DRAW");
	if (cursorIndex == 0 && this->choice == 1)
		this->result.setString("YOU LOST");
	if (cursorIndex == 0 && this->choice == 2)
		this->result.setString("YOU WON");
	if (cursorIndex == 1 && this->choice == 0)
		this->result.setString("YOU WON");
	if (cursorIndex == 1 && this->choice == 2)
		this->result.setString("YOU LOST");
	if (cursorIndex == 2 && this->choice == 0)
		this->result.setString("YOU LOST");
	if (cursorIndex == 2 && this->choice == 1)
		this->result.setString("YOU WON");

	return result;
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

sf::Sprite NPC::getCursorSprite() const
{
	return cursorSprite;
}

void NPC::drawNPCChoice()
{
	randomChoice();
	uploadNPCChoiceTexture();
	choiceSprite.setTexture(choiceTexture);
	choiceSprite.setScale(sf::Vector2f(3.f, 3.f));
	choiceSprite.setPosition(sf::Vector2f(340.f, 350.f));
	this->message.setString(" OLD MAN'S CHOICE");
}

sf::Sprite NPC::rightPressed()
{
	if (this->cursorIndex < 2)
		cursorIndex++;
	updateCursorSpritePosition();
	return cursorSprite;
}

sf::Sprite NPC::leftPressed()
{
	if (this->cursorIndex > 0)
		cursorIndex--;
	updateCursorSpritePosition();
	return cursorSprite;
}

void NPC::notEnoughCoins()
{
	this->message.setString("You don't have enough coins");
}
