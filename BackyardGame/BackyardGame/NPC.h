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
	int cursorIndex = 0;
	sf::Texture boardTexture;
	sf::Texture choiceTexture;
	sf::Texture cursorTexture;
	sf::Sprite boardSprite;
	sf::Sprite choiceSprite;
	sf::Sprite cursorSprite;
	sf::Text message;
	sf::Font messageFont;
	void randomChoice();
	void uploadNPCChoiceTexture();
	void loadCursorTexture();
public:
	NPC();
	~NPC();
// getters / setters
	sf::Text getNPCMessage() const;

// methods
std::vector<sf::Sprite> playRockPaperScissors();

};

