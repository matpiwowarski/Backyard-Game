#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Score
{
private:
	sf::Font font;
	sf::Text text;
	int score = 0;
public:
	Score();
	~Score();

	// methods
	void setText(std::string text);
	void setScore(int score);
	void render(sf::RenderTarget * target);
};

