#pragma once
#include "State.h"

class GameState : public State
{
private:
	Player player;
	Entity house, lake, red_tree;
	NPC old_man;
	Map map;
	Score score;
	std::vector <sf::Sprite> GameRPSToDraw;
	sf::Text NPCMessage;
	sf::Text NPCResultText;
	bool finishedMiniGame = false;
	void drawRPSSprites();
	void blockPlayer();
	void unblockPlayer();
	void moveCursor();
	void activateOldMan();
	void playWithOldMan();
	void setNPCFontMessage();
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	// methods
	void endState();
	void colisionPreventing(Player & player, Entity & object, const double &dt);
	void rotatingPlayer(Player & player, const double& dt);
	void checkDoor(Player & player, const double& dt);
	void updateKeybinds(const double& dt);
	void update(const double& dt);
	void render(sf::RenderTarget* target = nullptr);
};

