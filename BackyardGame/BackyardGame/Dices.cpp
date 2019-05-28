#include "Dices.h"



Dices::Dices()
{
	loadBoardTexture();
	loadOponnentBoardTexture();
	loadCursorTexture();
	this->message.setFont(messageFont);
	this->result.setFont(messageFont);
	this->message.setCharacterSize(24);
	this->result.setCharacterSize(24);
	this->message.setFillColor(sf::Color::White);
	this->result.setFillColor(sf::Color::White);
	sf::Vector2f position(290.f, 180.f);
	this->message.setPosition(position);
	boardSprite.setTexture(boardTexture);
	boardSprite.setScale(sf::Vector2f(3.f, 3.f));
	boardSprite.setPosition(sf::Vector2f(230.f, 402.f));
	oponnentBoardSprite.setTexture(oponnentBoardTexture);
	oponnentBoardSprite.setScale(sf::Vector2f(3.f, 3.f));
	oponnentBoardSprite.setPosition(sf::Vector2f(230.f, 180.f));
	cursorSprite.setTexture(cursorTexture);
	cursorSprite.setScale(sf::Vector2f(1 / 8.f, 1 / 8.f));
	updateCursorSpritePosition();
	fillDicesVector();
}


Dices::~Dices()
{
}

void Dices::uploadNPCChoiceTexture()
{
	sf::Texture textureForDice;
	for (int i = 1;i <= 6;i++) {
		if (this->oponnentDices[0].getChoice() + 1 == i) {
			if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw "ojojoj"; // error
			}
			else oponnentDices[0].setDiceTexture(textureForDice);
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->oponnentDices[1].getChoice() + 1 == i) {
			if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
			else oponnentDices[1].setDiceTexture(textureForDice);
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->oponnentDices[2].getChoice() + 1 == i) {
			if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
			else oponnentDices[2].setDiceTexture(textureForDice);
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->oponnentDices[3].getChoice() + 1 == i) {
			if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
			else oponnentDices[3].setDiceTexture(textureForDice);
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->oponnentDices[4].getChoice() + 1 == i) {
			if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
			else oponnentDices[4].setDiceTexture(textureForDice);
		}
	}
}



//getters

sf::Text Dices::getNPCResultText()
{
	sf::Vector2f position(340.f, 160.f);
	this->result.setPosition(position);
	if (this->playerScore > this->oponnentScore)
		this->result.setString("YOU WON");
	else if (this->playerScore == this->oponnentScore)
		this->result.setString("IT'S A DRAW");
	else if (this->playerScore < this->oponnentScore)
		this->result.setString("YOU LOST");

	return result;
}

sf::Sprite Dices::getOponnentBoardSprite() const
{
	return this->oponnentBoardSprite;
}

Dice Dices::getPlayerDice(int diceNumber)
{
	return this->playerDices[diceNumber];
}


Dice Dices::getOponnentDice(int diceNumber)
{
	return this->oponnentDices[diceNumber];
}



//change later, with templates(?)
//----------------------change later using another class Dice
void Dices::randomChoice()
{
}


void Dices::loadBoardTexture()
{
	if (!boardTexture.loadFromFile("../Assets/board_dices_player.png"))
	{
		throw; // error;
	}
}

void Dices::loadOponnentBoardTexture()
{
	if (!oponnentBoardTexture.loadFromFile("../Assets/board_dices_oponnent.png"))
	{
		throw; // error;
	}
}

void Dices::updateCursorSpritePosition()
{
	if (cursorIndex == 0)
	{
		cursorSprite.setPosition(sf::Vector2f(265.f, 525.f));
	}
	else if (cursorIndex == 1)
	{
		cursorSprite.setPosition(sf::Vector2f(325.f, 525.f));
	}
	else if (cursorIndex == 2)
	{
		cursorSprite.setPosition(sf::Vector2f(385.f, 525.f));
	}
	else if (cursorIndex == 3)
	{
		cursorSprite.setPosition(sf::Vector2f(445.f, 525.f));
	}
	else if (cursorIndex == 4)
	{
		cursorSprite.setPosition(sf::Vector2f(505.f, 525.f));
	}
	else if (cursorIndex == 5)
	{
		cursorSprite.setPosition(sf::Vector2f(565.f, 525.f));
	}
	
}

void Dices::fillDicesVector()
{
	Dice playerDice1, playerDice2, playerDice3, playerDice4, playerDice5, oponnentDice1, oponnentDice2, oponnentDice3, oponnentDice4, oponnentDice5;
	this->playerDices.push_back(playerDice1);
	this->playerDices.push_back(playerDice2);
	this->playerDices.push_back(playerDice3);
	this->playerDices.push_back(playerDice4);
	this->playerDices.push_back(playerDice5);

	this->oponnentDices.push_back(oponnentDice1);
	this->oponnentDices.push_back(oponnentDice2);
	this->oponnentDices.push_back(oponnentDice3);
	this->oponnentDices.push_back(oponnentDice4);
	this->oponnentDices.push_back(oponnentDice5);
}

void Dices::drawNPCChoice()
{
	sf::Sprite spriteForDice;

	this->oponnentDices[0].randomChoice();
	this->oponnentDices[1].randomChoice();
	this->oponnentDices[2].randomChoice();
	this->oponnentDices[3].randomChoice();
	this->oponnentDices[4].randomChoice();
	uploadNPCChoiceTexture();

	spriteForDice.setTexture(oponnentDices[0].getDiceTexture());
	spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
	spriteForDice.setPosition(sf::Vector2f(255.f, 208.f));
	oponnentDices[0].setDiceSprite(spriteForDice);

	spriteForDice.setTexture(oponnentDices[1].getDiceTexture());
	spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
	spriteForDice.setPosition(sf::Vector2f(315.f, 208.f));
	oponnentDices[1].setDiceSprite(spriteForDice);

	spriteForDice.setTexture(oponnentDices[2].getDiceTexture());
	spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
	spriteForDice.setPosition(sf::Vector2f(375.f, 208.f));
	oponnentDices[2].setDiceSprite(spriteForDice);

	spriteForDice.setTexture(oponnentDices[3].getDiceTexture());
	spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
	spriteForDice.setPosition(sf::Vector2f(435.f, 208.f));
	oponnentDices[3].setDiceSprite(spriteForDice);

	spriteForDice.setTexture(oponnentDices[4].getDiceTexture());
	spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
	spriteForDice.setPosition(sf::Vector2f(495.f, 208.f));
	oponnentDices[4].setDiceSprite(spriteForDice);

	this->message.setString(" HAT GUY'S DRAW");
}



sf::Sprite Dices::rightPressed()
{
	if (this->cursorIndex < 4)
		cursorIndex++;
	updateCursorSpritePosition();
	return cursorSprite;
}

sf::Sprite Dices::leftPressed()
{
	if (this->cursorIndex > 0)
		cursorIndex--;
	updateCursorSpritePosition();
	return cursorSprite;
}