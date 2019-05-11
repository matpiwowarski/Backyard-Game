#include "Score.h"

Score::Score()
{
	if (!this->font.loadFromFile("../Assets/fonts/CarterOne.ttf"))
	{
		throw; //error;
	}
	else
	{
		this->text.setFont(this->font);
		this->text.setString(std::to_string(this->score));
		this->text.setCharacterSize(24);
		this->text.setFillColor(sf::Color::White);
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
