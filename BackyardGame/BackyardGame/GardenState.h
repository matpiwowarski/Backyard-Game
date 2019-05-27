#pragma once
#include "GameState.h"
class GardenState :
	public GameState
{
private:
	Entity fence_up, fence_down1, fence_down2, fence_left, fence_right, flowers1, flowers2, chest, rock;
	Dices dice_guy;    
	void checkIfPlayerLeftGarden();
	//Dices
	std::vector <sf::Sprite> GameDicesToDraw;
	void moveCursor();
	void activateDiceGuy();
	void drawDiceGuyChoice();
	void drawDicesSprites();
	void playDices();
	void DicesResult();
	void finishDices();
	void checkDicesAction();
public:
	GardenState();
	GardenState(sf::RenderWindow* window);
	~GardenState();

	//setters/getters

	//methods
	void checkMovementLimits(const double& dt); /// TO DO
	void colisionPreventEverything(const double &dt);
	void update(const double& dt);
	void render(sf::RenderTarget* target = nullptr);
};

