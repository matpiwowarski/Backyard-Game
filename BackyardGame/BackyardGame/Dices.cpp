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
}


Dices::~Dices()
{
}

void Dices::uploadNPCChoiceTexture()
{
	sf::Texture textureForDice;
	for (int i = 1;i <= 6;i++) {
		if (this->oponnentDice1.getChoice() + 1 == i) {
			if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw "ojojoj"; // error
			}
			else oponnentDice1.setDiceTexture(textureForDice);
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->oponnentDice2.getChoice() + 1 == i) {
			if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
			else oponnentDice2.setDiceTexture(textureForDice);
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->oponnentDice3.getChoice() + 1 == i) {
			if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
			else oponnentDice3.setDiceTexture(textureForDice);
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->oponnentDice4.getChoice() + 1 == i) {
			if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
			else oponnentDice4.setDiceTexture(textureForDice);
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->oponnentDice5.getChoice() + 1 == i) {
			if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
			else oponnentDice5.setDiceTexture(textureForDice);
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

Dice Dices::getPlayerDice1()
{
	return this->playerDice1;
}

Dice Dices::getPlayerDice2()
{
	return this->playerDice2;
}

Dice Dices::getPlayerDice3()
{
	return this->playerDice3;
}

Dice Dices::getPlayerDice4()
{
	return this->playerDice4;
}

Dice Dices::getPlayerDice5()
{
	return this->playerDice5;
}

Dice Dices::getOponnentDice1()
{
	return this->oponnentDice1;
}

Dice Dices::getOponnentDice2()
{
	return this->oponnentDice2;
}

Dice Dices::getOponnentDice3()
{
	return this->oponnentDice3;
}

Dice Dices::getOponnentDice4()
{
	return this->oponnentDice4;
}

Dice Dices::getOponnentDice5()
{
	return this->oponnentDice5;
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
		cursorSprite.setPosition(sf::Vector2f(275.f, 525.f));
	}
	else if (cursorIndex == 1)
	{
		cursorSprite.setPosition(sf::Vector2f(390.f, 525.f));
	}
	else if (cursorIndex == 2)
	{
		cursorSprite.setPosition(sf::Vector2f(490.f, 525.f));
	}
	else if (cursorIndex == 3)
	{
		cursorSprite.setPosition(sf::Vector2f(590.f, 525.f));
	}
	else if (cursorIndex == 4)
	{
		cursorSprite.setPosition(sf::Vector2f(690.f, 525.f));
	}
	else if (cursorIndex == 5)
	{
		cursorSprite.setPosition(sf::Vector2f(790.f, 525.f));
	}
	
}

void Dices::drawNPCChoice()
{
	sf::Sprite spriteForDice;

	this->oponnentDice1.randomChoice();
	this->oponnentDice2.randomChoice();
	this->oponnentDice3.randomChoice();
	this->oponnentDice4.randomChoice();
	this->oponnentDice5.randomChoice();
	uploadNPCChoiceTexture();

	spriteForDice.setTexture(oponnentDice1.getDiceTexture());
	spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
	spriteForDice.setPosition(sf::Vector2f(255.f, 208.f));
	oponnentDice1.setDiceSprite(spriteForDice);

	spriteForDice.setTexture(oponnentDice2.getDiceTexture());
	spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
	spriteForDice.setPosition(sf::Vector2f(315.f, 208.f));
	oponnentDice2.setDiceSprite(spriteForDice);

	spriteForDice.setTexture(oponnentDice3.getDiceTexture());
	spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
	spriteForDice.setPosition(sf::Vector2f(375.f, 208.f));
	oponnentDice3.setDiceSprite(spriteForDice);

	spriteForDice.setTexture(oponnentDice4.getDiceTexture());
	spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
	spriteForDice.setPosition(sf::Vector2f(435.f, 208.f));
	oponnentDice4.setDiceSprite(spriteForDice);

	spriteForDice.setTexture(oponnentDice5.getDiceTexture());
	spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
	spriteForDice.setPosition(sf::Vector2f(495.f, 208.f));
	oponnentDice5.setDiceSprite(spriteForDice);

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