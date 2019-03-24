#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	// variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	// initialization
	void initWindow();
public:
	// constructors/destructors
	Game();
	virtual ~Game();

	// functions
	void updateSFMLEvents();
	void update();
	void render();
	void run();

};

