#pragma once
#include "BackyardState.h"
#include "HouseState.h"

class Game
{
private:
	// variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	double dt;

	std::stack<State*> states;

	// initialization
	void initWindow();
	void initStates();
public:
	// constructors/destructors
	Game();
	virtual ~Game();

	// update
	void updateDt();
	void updateSFMLEvents();
	void update();
	// render
	void render();
	// other
	void run();
	void endGame();

};

