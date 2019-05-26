#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Entity.h"

// Singleton pattern

class Score
{
private:
	sf::Font font;
	sf::Text text;
	sf::Texture BoardTexture;
	Entity board;
	int score = 10;
	Score();
public:
	static Score & getInstance();

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
