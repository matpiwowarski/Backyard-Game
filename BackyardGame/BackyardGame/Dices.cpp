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
	for (int i = 1;i <= 6;i++) {
		if (this->choice+1 == i) {
			if (!choiceTexture.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->choice2+1 == i) {
			if (!choiceTexture2.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->choice3+1 == i) {
			if (!choiceTexture3.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->choice4+1 == i) {
			if (!choiceTexture4.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
		}
	}
	for (int i = 1;i <= 6;i++) {
		if (this->choice5+1 == i) {
			if (!choiceTexture5.loadFromFile("../Assets/dice_" + std::to_string(i) + ".png"))
			{
				throw; // error
			}
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
	return oponnentBoardSprite;
}
//change later, with templates(?)
void Dices::randomChoice()
{
	std::default_random_engine engine;
	std::uniform_real_distribution<double> distribution;
	auto czas = std::chrono::system_clock::now();
	auto interval = czas.time_since_epoch();
	engine.seed(interval.count());

	int random = distribution(engine) * 100;
	this->choice = random % 6;
}

void Dices::randomChoice2()
{
	std::default_random_engine engine;
	std::uniform_real_distribution<double> distribution;
	auto czas = std::chrono::system_clock::now();
	auto interval = czas.time_since_epoch();
	engine.seed(interval.count());

	int random = distribution(engine) * 100;
	this->choice2 = random % 6;
}


void Dices::randomChoice3()
{
	std::default_random_engine engine;
	std::uniform_real_distribution<double> distribution;
	auto czas = std::chrono::system_clock::now();
	auto interval = czas.time_since_epoch();
	engine.seed(interval.count());

	int random = distribution(engine) * 100;
	this->choice3 = random % 6;
}

void Dices::randomChoice4()
{
	std::default_random_engine engine;
	std::uniform_real_distribution<double> distribution;
	auto czas = std::chrono::system_clock::now();
	auto interval = czas.time_since_epoch();
	engine.seed(interval.count());

	int random = distribution(engine) * 100;
	this->choice4 = random % 6;
}

void Dices::randomChoice5()
{
	std::default_random_engine engine;
	std::uniform_real_distribution<double> distribution;
	auto czas = std::chrono::system_clock::now();
	auto interval = czas.time_since_epoch();
	engine.seed(interval.count());

	int random = distribution(engine) * 100;
	this->choice5 = random % 6;
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
	randomChoice();
	randomChoice2();
	randomChoice3();
	randomChoice4();
	randomChoice5();
	uploadNPCChoiceTexture();
	choiceSprite.setTexture(choiceTexture);
	choiceSprite.setScale(sf::Vector2f(3.f, 3.f));
	choiceSprite.setPosition(sf::Vector2f(255.f, 208.f));

	choiceSprite2.setTexture(choiceTexture2);
	choiceSprite2.setScale(sf::Vector2f(3.f, 3.f));
	choiceSprite2.setPosition(sf::Vector2f(315.f, 208.f));

	choiceSprite3.setTexture(choiceTexture3);
	choiceSprite3.setScale(sf::Vector2f(3.f, 3.f));
	choiceSprite3.setPosition(sf::Vector2f(375.f, 208.f));

	choiceSprite4.setTexture(choiceTexture4);
	choiceSprite4.setScale(sf::Vector2f(3.f, 3.f));
	choiceSprite4.setPosition(sf::Vector2f(435.f, 208.f));

	choiceSprite5.setTexture(choiceTexture5);
	choiceSprite5.setScale(sf::Vector2f(3.f, 3.f));
	choiceSprite5.setPosition(sf::Vector2f(495.f, 208.f));

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