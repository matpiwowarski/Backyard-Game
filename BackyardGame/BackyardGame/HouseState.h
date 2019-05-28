#pragma once
#include "GameState.h"
#include <vector>
class HouseState : public GameState
{
private:
	sf::Clock NPCClock;
	int bet = 0;
	int cursorIndex = 0;
	std::vector <sf::Sprite> miniGameSpritesToDraw;
	void checkIfPlayerLeftHouse();
	ArmWrestler skeleton = ArmWrestler::getInstance();
	ArmWrestler vampire = ArmWrestler::getInstance();
	ArmWrestler priest = ArmWrestler::getInstance();
	std::vector<Entity> flags;
	sf::Text BoardInfo1;
	sf::Text BoardInfo2;
	sf::Font BoardInfoFont;
	void initializeBoardInfo();
	void initializeFlags();
	void initializeNPCs();
	void checkArmWrestlingAction();
	void playArmWrestling(ArmWrestler armwrestler);
	void finishArmWrestling();
	void DisplayBoardAndPlay(ArmWrestler armwrestler);
	void drawMiniGameSprites();
	void miniGameResults();
	void fastClicking();
	void updateNPCClock();
public:
	HouseState();
	HouseState(sf::RenderWindow* window);
	~HouseState();

	// setters/getters

	// methods
	void checkMovementLimits(const double& dt); /// TO DO
	void colisionPreventEverything(const double &dt);
	void update(const double& dt);
	void render(sf::RenderTarget* target = nullptr);
};
