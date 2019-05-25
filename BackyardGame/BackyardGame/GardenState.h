#pragma once
#include "GameState.h"
class GardenState :
	public GameState
{
private:
	Entity fence_up, fence_down1, fence_down2, fence_left, fence_right, flowers1, flowers2, chest, rock;
	RPS dice_guy;    ///change to dice class after making it
	std::vector <sf::Sprite> miniGameSpritesToDraw;
	void checkIfPlayerLeftGarden();
public:
	GardenState();
	GardenState(sf::RenderWindow* window);
	~GardenState();

	//setters/getters

	//methods
	void colisionPreventEverything(const double &dt);
	void update(const double& dt);
	void render(sf::RenderTarget* target = nullptr);
};

