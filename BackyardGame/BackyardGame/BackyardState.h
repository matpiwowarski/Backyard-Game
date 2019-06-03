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
	void moveCursor();			// move cursor while choosing RPS
	void activateOldMan();		// draw board and cursor
	void drawOldManChoice();
	void drawRPSSprites();
	void playRPS();				// check score to play, block player and start mini game
	void RPSResult();			// delete cursor and display result WIN/DRAW/LOSE
	void finishRPS();			// clear mini game after space/enter press
	void checkRPSAction();		
	template<typename Type> void setTexture(Type & t, int i);
	template<typename a, typename b> void colisionPreventing(a& t1, b& t2, const double& dt);
public:
	BackyardState();
	BackyardState(sf::RenderWindow* window);
	~BackyardState();
	void checkMovementLimits(const double& dt);
	void checkDoor(Player & player, const double& dt); // to enter house
	void colisionPreventEverything(const double &dt);
	void update(const double& dt);
	void render(sf::RenderTarget* target = nullptr);
};
