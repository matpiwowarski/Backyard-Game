#pragma once
#include "GameState.h"
class BackyardState : public GameState
{
private:
	Entity house, lake, red_tree;
	RPS old_man;
	bool areDoorOpen=false;
	std::vector <sf::Sprite> GameRPSToDraw;
	void checkIfPlayerEnteredGarden();
	// RPS:
	void moveCursor();
	void activateOldMan();
	void drawOldManChoice();
	void drawRPSSprites();
	void playRPS();
	void RPSResult();
	void finishRPS();
	void checkRPSAction();
	template<typename Type> void setTexture(Type & t, int i);
	template<typename a, typename b> void colisionPreventing(a& t1, b& t2, const double& dt);
public:
	BackyardState();
	BackyardState(sf::RenderWindow* window);
	~BackyardState();
	void checkMovementLimits(const double& dt);
	void checkDoor(Player & player, const double& dt);
	void colisionPreventEverything(const double &dt);
	void update(const double& dt);
	void render(sf::RenderTarget* target = nullptr);
};
