#pragma once
#include "State.h"

class GameState : public State
{
private:
	Player player;
	Entity house, lake;
	Map map;
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	// methods
	void endState();
	void colisionPreventing(Player & player, Entity & object, const double &dt);
	void updateKeybinds(const double& dt);
	void update(const double& dt);
	void render(sf::RenderTarget* target = nullptr);
};

