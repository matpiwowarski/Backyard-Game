#pragma once
#include "Entity.h"
#include "Player.h"
#include "NPC.h"
#include "RPS.h"
#include "Map.h"
#include "Score.h"

class State
{
protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;
	bool changedMap = false;
public:
	State();
	State(sf::RenderWindow* window);
	virtual ~State();

	bool isChangedMap() const;
	bool getQuit() const;

	virtual void checkQuit();
	virtual void endState() = 0;
	virtual void updateKeybinds(const double & dt) = 0;
	virtual void update(const double & dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

