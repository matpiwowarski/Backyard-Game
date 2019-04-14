#pragma once

#include "State.h"

class Game
{
private:
	// variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;
	// initialization
	void initWindow();
public:
	// constructors/destructors
	Game();
	virtual ~Game();

	// functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();

};

