#pragma once
#include "State.h"

class GameState : public State
{
private:
	Player player;
	Entity house;
	Map map;
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	// methods
	void endState();
	void updateKeybinds(const double& dt);
	void update(const double& dt);
	void render(sf::RenderTarget* target = nullptr);
};

