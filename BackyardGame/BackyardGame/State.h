#pragma once
#include "Entity.h"
#include "Player.h"
#include "NPC.h"
#include "RPS.h"
#include "Map.h"
#include "Score.h"
#include "Soundtrack.h"

class State
{
protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	Soundtrack music;
	bool quit;
	bool enteredHouse = false;
	bool enteredGarden = false;
	bool backToBackyard = false;
public:
	State();
	State(sf::RenderWindow* window);
	virtual ~State();

	// setters / getters
	void setEnetredHouse(bool enteredHouse);
	void setEnteredGarden(bool enteredGarden);
	void setBackToBackyard(bool backToBackyard);
	bool hasEnteredHouse() const;
	bool hasEnteredGarden() const;
	bool hasBackToBackyard() const;
	bool getQuit() const;

	virtual void checkQuit();
	virtual void endState() = 0;
	virtual void updateKeybinds(const double & dt) = 0;
	virtual void update(const double & dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

