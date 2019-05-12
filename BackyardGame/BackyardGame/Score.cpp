#include "Score.h"

Score::Score()
{
	if (!this->font.loadFromFile("../Assets/fonts/CarterOne.ttf")) // PressStart2P-Regular.ttf
	{
		throw; //error;
	}
	else
	{
		this->text.setFont(this->font);
		this->text.setString(std::to_string(this->score));
		this->text.setCharacterSize(24);
		this->text.setFillColor(sf::Color::Black);
		sf::Vector2f position(770.f, 0.f);
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
	this->text.setString(std::to_string(score));
}


void Score::render(sf::RenderTarget * target)
{
	target->draw(this->text);
}

void Score::update(const double & dt)
{
	if (score > 99)
	{
		this->text.setPosition(sf::Vector2f(750.f, 0.f));
		if (score > 999)
		{
			this->text.setPosition(sf::Vector2f(730.f, 0.f));
			if (score > 9999)
			{
				this->text.setPosition(sf::Vector2f(710.f, 0.f));
				if (score > 99999)
				{
					this->text.setPosition(sf::Vector2f(690.f, 0.f));
				}
			}
		}
	}
}

void Score::add(int score)
{
	this->score += score;
	this->text.setString(std::to_string(this->score));
}

void Score::subtract(int score)
{
	this->score -= score;
	this->text.setString(std::to_string(this->score));
}
