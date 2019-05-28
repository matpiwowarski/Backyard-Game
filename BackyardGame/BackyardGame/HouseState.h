#pragma once
#include "GameState.h"
#include <vector>
class HouseState : public GameState
{
private:
	int bet = 0;
	std::vector <sf::Sprite> miniGameSpritesToDraw;
	void checkIfPlayerLeftHouse();
	ArmWrestler skeleton = ArmWrestler::ArmWrestler(2);
	ArmWrestler vampire = ArmWrestler::ArmWrestler(1);
	ArmWrestler priest = ArmWrestler::ArmWrestler(0);
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
