#include "Dices.h"



Dices::Dices()
{
	loadBoardTexture();
	loadOponnentBoardTexture();
	loadDiceButtonTexture();
	loadCursorTexture();

	this->message.setFont(messageFont);
	this->result.setFont(messageFont);
	this->rerollsText.setFont(messageFont);
	this->buttonText.setFont(messageFont);

	this->message.setCharacterSize(24);
	this->result.setCharacterSize(24);
	this->rerollsText.setCharacterSize(20);
	this->buttonText.setCharacterSize(16);

	this->message.setFillColor(sf::Color::White);
	this->result.setFillColor(sf::Color::White);
	this->rerollsText.setFillColor(sf::Color::White);
	this->buttonText.setFillColor(sf::Color::White);

	sf::Vector2f position(290.f, 180.f);
	this->message.setPosition(position);

	sf::Vector2f rerollsTextPosition(230.f, 400.f);
	this->rerollsText.setPosition(rerollsTextPosition);

	sf::Vector2f buttonTextPosition(635.f, 440.f);
	this->buttonText.setPosition(buttonTextPosition);

	boardSprite.setTexture(boardTexture);
	boardSprite.setScale(sf::Vector2f(3.f, 3.f));
	boardSprite.setPosition(sf::Vector2f(230.f, 402.f));

	oponnentBoardSprite.setTexture(oponnentBoardTexture);
	oponnentBoardSprite.setScale(sf::Vector2f(3.f, 3.f));
	oponnentBoardSprite.setPosition(sf::Vector2f(230.f, 180.f));

	diceButtonSprite.setTexture(diceButtonTexture);
	diceButtonSprite.setScale(sf::Vector2f(3.f, 3.f));
	diceButtonSprite.setPosition(sf::Vector2f(630.f, 415.f));

	cursorSprite.setTexture(cursorTexture);
	cursorSprite.setScale(sf::Vector2f(1 / 8.f, 1 / 8.f));
	updateCursorSpritePosition();

	fillDicesVector();
	setDicesTexts(2);
}


Dices::~Dices()
{
}

void Dices::uploadNPCChoiceTexture()
{
	sf::Texture textureForDice;
	try
	{
		for (int j = 0; j <= 4; j++) {
			for (int i = 1; i <= 6; i++) {
				if (this->oponnentDices[j].getChoice() + 1 == i) {
					if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
					{
						throw -1; // error
					}
					else oponnentDices[j].setDiceTexture(textureForDice);
				}
			}
		}
	}
	catch (int)
	{
		std::cout << "Problem with dice texture loading";
	}

}


void Dices::uploadPlayersChoiceTexture()
{
	sf::Texture textureForDice;

	try
	{
		for (int j = 0; j <= 4; j++) {
			for (int i = 1; i <= 6; i++) {
				if (this->playerDices[j].getChoice() + 1 == i) {
					if (!textureForDice.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
					{
						throw -1; // error
					}
					else playerDices[j].setDiceTexture(textureForDice);
				}
			}
		}
	}
	catch (int)
	{
		std::cout << "Problem with dice texture loading";
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

sf::Text Dices::getButtonText() const
{
	return this->buttonText;
}

sf::Text Dices::getRerollsText() const
{
	return this->rerollsText;
}

sf::Sprite Dices::getOponnentBoardSprite() const
{
	return this->oponnentBoardSprite;
}

sf::Sprite Dices::getDiceButtonSprite() const
{
	return this->diceButtonSprite;
}
Dice Dices::getPlayerDice(int diceNumber)
{
	return this->playerDices[diceNumber];
}


Dice Dices::getOponnentDice(int diceNumber)
{
	return this->oponnentDices[diceNumber];
}


//methods

void Dices::randomChoice()
{
}


void Dices::loadBoardTexture()
{
	try
	{
		if (!boardTexture.loadFromFile("../Assets/board_dices_player.png"))
		{
			throw -1; // error;
		}
	}
	catch (int)
	{
		std::cout << "Problem with board texture loading";
	}


}

void Dices::loadOponnentBoardTexture()
{
	try
	{
		if (!oponnentBoardTexture.loadFromFile("../Assets/board_dices_oponnent.png"))
		{
			throw - 1; // error;
		}
	}
	catch (int)
	{
		std::cout << "Problem with board texture loading";
	}

}

void Dices::loadDiceButtonTexture()
{
	try
	{
		if (!diceButtonTexture.loadFromFile("../Assets/dice_button.png"))
		{
			throw - 1; // error;
		}
	}
	catch (int)
	{
		std::cout << "Problem with dice texture loading";
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
		cursorSprite.setPosition(sf::Vector2f(655.f, 500.f));
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
	this->message.setString(" HAT GUY'S DRAW");
}

void Dices::setOponnentsDicesSprites()
{
	sf::Sprite spriteForDice;

	for (int i = 0;i <= 4;i++) {
		this->oponnentDices[i].randomChoice();
	}
	uploadNPCChoiceTexture();

	float xForVector = 0.f;

	for (int i = 0;i <= 4;i++) {
		spriteForDice.setTexture(oponnentDices[i].getDiceTexture());
		spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
		spriteForDice.setPosition(sf::Vector2f(xForVector + 255.f, 208.f));
		oponnentDices[i].setDiceSprite(spriteForDice);

		xForVector += 60.f;
	}
}

void Dices::setPlayersDicesSprites() 
{
	sf::Sprite spriteForDice;

	for (int i = 0;i <= 4;i++) {
		this->playerDices[i].randomChoice();
	}
	uploadPlayersChoiceTexture();

	float xForVector = 0.f;

	for (int i = 0;i <= 4;i++) {
		spriteForDice.setTexture(playerDices[i].getDiceTexture());
		spriteForDice.setScale(sf::Vector2f(3.f, 3.f));
		spriteForDice.setPosition(sf::Vector2f(xForVector + 255.f, 432.f));
		playerDices[i].setDiceSprite(spriteForDice);

		xForVector += 60.f;
	}
}

void Dices::setDicesTexts(int reroll)
{
	this->buttonText.setString(" Re-roll!");
	this->rerollsText.setString(" Number of re-rolls left: " + std::to_string(reroll));
}



sf::Sprite Dices::rightPressed()
{
	if (this->cursorIndex < 5)
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