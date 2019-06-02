#include "Score.h"

Score::Score()
{
	score = 10;

	try
	{
		if (!this->font.loadFromFile("../Assets/fonts/CarterOne.ttf")) // PressStart2P-Regular.ttf
		{
			throw -1; // error;
		}
		else if (!this->BoardTexture.loadFromFile("../Assets/board.png"))
		{
			throw -2; // error;
		}
	}
	catch (int i)
	{
		if (i == -1)
		{
			std::cout << "Problem with font loading";
		}
		else
		{
			std::cout << "Problem with board texture loading";
		}
	}

	this->board.getSprite().setTexture(BoardTexture);
	this->board.getSprite().setPosition(sf::Vector2f(688.f, 0.f));
	this->board.getSprite().scale(sf::Vector2f(0.5, 0.5));
	this->text.setFont(this->font);
	this->text.setString(std::to_string(this->score));
	this->text.setCharacterSize(24);
	this->text.setFillColor(sf::Color::White);
	sf::Vector2f position(730.f, 0.f);
	this->text.setPosition(position);

}

Score & Score::getInstance()
{
	static Score instance;
	return instance;
}

void Score::setText(std::string text)
{
	this->text.setString(text);
	this->text.setCharacterSize(24);	
}
void Score::setScore(int score)
{
	this->score = score;
	this->text.setString(std::to_string(this->score));
}

int Score::getScore() const
{
	return score;
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
	if (score > 99)
	{
		this->text.setPosition(sf::Vector2f(720.f, 0.f));
		if (score > 999)
		{
			this->text.setPosition(sf::Vector2f(710.f, 0.f));
			if (score > 9999)
			{
				this->text.setPosition(sf::Vector2f(700.f, 0.f));
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
