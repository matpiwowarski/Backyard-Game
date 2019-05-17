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
	void loadBoardTexture();
	void updateCursorSpritePosition();
public:
	NPC();
	~NPC();
// getters / setters
	sf::Sprite getBoardSprite() const;
	sf::Sprite getNPCChoiceSprite() const;
	sf::Sprite getCursorSprite() const;
	sf::Text getNPCMessage() const;

// methods
void playRockPaperScissors(); // return cursor sprite
sf::Sprite rightPressed(); // return cursor sprite
sf::Sprite leftPressed(); // return cursor sprite
};

