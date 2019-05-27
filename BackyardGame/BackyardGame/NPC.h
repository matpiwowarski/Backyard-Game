#pragma once
#include "Entity.h"
#include <random>
#include <chrono>
#include <ctime>
#include <vector>

class NPC : public Entity
{
protected: 
	int choice;
	int cursorIndex = 0;
	sf::Texture boardTexture, oponnentBoardTexture;
	sf::Texture choiceTexture;
	sf::Texture cursorTexture;
	sf::Sprite boardSprite, oponnentBoardSprite;
	sf::Sprite choiceSprite;
	sf::Sprite cursorSprite;
	sf::Text message;
	sf::Text result;
	sf::Font messageFont;
	virtual void uploadNPCChoiceTexture()=0;
	void loadCursorTexture();
	virtual void randomChoice()=0;
	virtual void loadBoardTexture()=0;
	virtual void updateCursorSpritePosition()=0;
public:
	NPC();
	~NPC();
// getters / setters
	virtual sf::Sprite getBoardSprite() const;
	virtual sf::Sprite getNPCChoiceSprite() const;
	virtual sf::Texture getNPCChoiceTexture() const;
	virtual sf::Sprite getCursorSprite() const;
	virtual sf::Text getNPCMessage() const;
	virtual sf::Text getNPCResultText();
	virtual sf::Font getMessageFont() const;

// methods
virtual void drawNPCChoice()=0;
virtual sf::Sprite rightPressed()=0; // return cursor sprite
virtual sf::Sprite leftPressed()=0; // return cursor sprite
void notEnoughCoins(); // change message
};

