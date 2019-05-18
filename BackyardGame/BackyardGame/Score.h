#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Entity.h"

class Score
{
private:
	sf::Font font;
	sf::Text text;
	sf::Texture BoardTexture;
	Entity board;
	int score = 10; // starting score
public:
	Score();
	~Score();
	// getters/setters
	void setText(std::string text);
	void setScore(int score);
	int getScore() const;
	Entity & getEntity();
	// methods
	void render(sf::RenderTarget * target);
	void update(const double & dt);
	void add(int score);
	void subtract(int score);

};

