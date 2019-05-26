#pragma once
#include "State.h"

class GameState : public State
{
protected:
	Player player;
	Map map;
	Score & score = Score::getInstance();
	sf::Text NPCMessage;
	sf::Text NPCResultText;
	bool finishedMiniGame = false;
	// private methods:
	void blockPlayer();
	void unblockPlayer();
public:
	GameState();
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	// methods
	void endState();
	void colisionPreventing(Player & player, Entity & object, const double &dt);;
	void rotatingPlayer(Player & player, const double& dt);
	void updateKeybinds(const double& dt);
	virtual void checkMovementLimits(const double& dt) = 0;
	virtual void colisionPreventEverything(const double &dt) = 0;
	virtual void update(const double& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

