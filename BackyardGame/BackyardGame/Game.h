#pragma once

#include "GameState.h"

class Game
{
private:
	// variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	// initialization
	void initWindow();
	void initStates();
public:
	// constructors/destructors
	Game();
	virtual ~Game();

	// methods
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();

};

