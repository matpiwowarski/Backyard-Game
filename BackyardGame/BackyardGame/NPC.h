#pragma once
#include "Entity.h"
#include <random>
#include <chrono>
#include <ctime>
#include <vector>

class NPC : public Entity
{
private: 
	int choice;
	sf::Texture boardTexture;
	sf::Texture choiceTexture;
	sf::Sprite boardSprite;
	sf::Sprite choiceSprite;
	sf::Text message;
	sf::Font messageFont;
	void randomChoice();
	void uploadChoiceTexture();
public:
	NPC();
	~NPC();
// getters / setters
	sf::Text getNPCMessage() const;

// methods
std::vector<sf::Sprite> playRockPaperScissors();

};

