#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <stack>

class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	bool getQuit() const;

	virtual void checkQuit();
	virtual void endState() = 0;
	virtual void updateKeybinds(const double & dt) = 0;
	virtual void update(const double & dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

