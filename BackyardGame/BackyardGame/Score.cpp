#include "Score.h"

int Score::score; // static variable
Score::Score()
{
	if (!this->font.loadFromFile("../Assets/fonts/CarterOne.ttf")) // PressStart2P-Regular.ttf
	{
		throw; // error;
	}
	else if(!this->BoardTexture.loadFromFile("../Assets/board.png"))
	{
		throw; // error;
	}
	else
	{
		this->board.getSprite().setTexture(BoardTexture);
		this->board.getSprite().setPosition(sf::Vector2f(688.f, 0.f));
		this->board.getSprite().scale(sf::Vector2f(0.5, 0.5));
		this->text.setFont(this->font);
		this->text.setString(std::to_string(Score::score));
		this->text.setCharacterSize(24);
		this->text.setFillColor(sf::Color::White);
		sf::Vector2f position(730.f, 0.f);
		this->text.setPosition(position);
	}
}


Score::~Score()
{

}

void Score::setText(std::string text)
{
	this->text.setString(text);
	this->text.setCharacterSize(24);	
}
void Score::setScore(int score)
{
	Score::score = score;
	this->text.setString(std::to_string(score));
}

int Score::getScore() const
{
	return Score::score;
}

Entity & Score::getEntity()
{
	return this->board;
}


void Score::render(sf::RenderTarget * target)
{
	board.render(target);
	target->draw(this->text);
}

void Score::update(const double & dt)
{
	if (Score::score > 99)
	{
		this->text.setPosition(sf::Vector2f(720.f, 0.f));
		if (Score::score > 999)
		{
			this->text.setPosition(sf::Vector2f(710.f, 0.f));
			if (Score::score > 9999)
			{
				this->text.setPosition(sf::Vector2f(700.f, 0.f));
				if (Score::score > 99999)
				{
					this->text.setPosition(sf::Vector2f(690.f, 0.f));
				}
			}
		}
	}
}

void Score::add(int score)
{
	Score::score += score;
	this->text.setString(std::to_string(Score::score));
}

void Score::subtract(int score)
{
	Score::score -= score;
	this->text.setString(std::to_string(Score::score));
}
