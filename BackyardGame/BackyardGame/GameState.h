#pragma once
#include "State.h"

class GameState : public State
{
private:
	Player player;
	Entity house, lake, red_tree;
	RPS old_man;
	Map map;
	Score score;
	std::vector <sf::Sprite> GameRPSToDraw;
	sf::Text NPCMessage;
	sf::Text NPCResultText;
	bool finishedMiniGame = false;
	// private methods:
	void blockPlayer();
	void unblockPlayer();
		// RPS:
	void moveCursor();
	void activateOldMan();
	void drawOldManChoice();
	void drawRPSSprites();
	void playRPS();
	void RPSResult();
	void finishRPS();
	void checkRPSAction();
	
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	// methods
	void endState();
	void colisionPreventing(Player & player, Entity & object, const double &dt);
	void colisionPreventing(const double &dt);
	void rotatingPlayer(Player & player, const double& dt);
	void checkDoor(Player & player, const double& dt);
	void updateKeybinds(const double& dt);
	void update(const double& dt);
	void render(sf::RenderTarget* target = nullptr);
};

