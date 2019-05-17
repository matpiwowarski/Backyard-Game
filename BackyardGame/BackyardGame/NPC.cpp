#include "NPC.h"



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


NPC::NPC()
{
	if (!this->messageFont.loadFromFile("../Assets/fonts/CarterOne.ttf")) // PressStart2P-Regular.ttf
	{
		throw; // error;
	}
	else
	{
		this->message.setFont(messageFont);
		this->message.setString(" OLD MAN'S CHOICE");
		this->message.setCharacterSize(24);
		this->message.setFillColor(sf::Color::Black);
		sf::Vector2f position(290.f, 450.f);
		this->message.setPosition(position);
	}
}


NPC::~NPC()
{
}

sf::Text NPC::getNPCMessage() const
{
	return this->message;
}

std::vector<sf::Sprite> NPC::playRockPaperScissors()
{
	if (!boardTexture.loadFromFile("../Assets/board_rps.png"))
	{
		throw; // error
	}
	else
	{
		randomChoice();
		loadCursorTexture();
		uploadNPCChoiceTexture();
		cursorSprite.setTexture(cursorTexture);
		choiceSprite.setTexture(choiceTexture);
		boardSprite.setTexture(boardTexture);
		choiceSprite.setScale(sf::Vector2f(3.f, 3.f));
		boardSprite.setScale(sf::Vector2f(3.f, 3.f));
		cursorSprite.setScale(sf::Vector2f(1/8.f, 1/8.f));
		choiceSprite.setPosition(sf::Vector2f(340.f, 350.f));
		boardSprite.setPosition(sf::Vector2f(230.f, 252.f));
		cursorSprite.setPosition(sf::Vector2f(275.f, 325.f));

		std::vector<sf::Sprite> toDraw;
		toDraw.push_back(boardSprite);
		toDraw.push_back(choiceSprite);
		toDraw.push_back(cursorSprite);

		return toDraw;
	}
}
