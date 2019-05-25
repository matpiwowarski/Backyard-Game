#pragma once
#include "GameState.h"
class GardenState :
	public GameState
{
private:
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

