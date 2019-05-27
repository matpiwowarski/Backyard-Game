#pragma once
#include "GameState.h"
class HouseState : public GameState
{
private:
	std::vector <sf::Sprite> miniGameSpritesToDraw;
	void checkIfPlayerLeftHouse();
	ArmWrestler skeleton;
	void checkArmWrestlingAction();
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
