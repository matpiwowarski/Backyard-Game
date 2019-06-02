#pragma once
#include "GameState.h"
#include <vector>
class HouseState : public GameState
{
private:
	sf::Clock NPCClock;
	int bet = 0;
	int cursorIndex = 0;
	bool usedLadder = false;
	static bool hiddenLadder;
	std::vector <sf::Sprite> miniGameSpritesToDraw;
	void checkIfPlayerLeftHouse();
	ArmWrestler skeleton = ArmWrestler::getInstance();
	ArmWrestler vampire = ArmWrestler::getInstance();
	ArmWrestler priest = ArmWrestler::getInstance();
	Entity ladder;
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
	void DisplayBoard(ArmWrestler armwrestler);
	void drawMiniGameSprites();
	void miniGameResults();
	void fastClicking();
	void checkIsLadderUsed();
	void checkEndGame();
	template<typename Type> void setTexture(Type & t, int i);
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
